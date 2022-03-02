#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 1024

int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

void addfd( int epollfd, int fd )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}


int main(int argc, char* argv[]){
    if(argc <= 2){
        printf("argc in not enough");
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_address.sin_addr);
    server_address.sin_port = htons(port);
    int server_sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(server_sockfd >= 0);

    int pipefd[2];
    int ret = pipe( pipefd );
    assert( ret != -1 );

    char buf[BUFFER_SIZE];

    bool stop_flag = false;
    int flag = connect(server_sockfd, (struct sockaddr*)& server_address, sizeof(server_address));

    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    assert(epollfd != -1);
    addfd(epollfd, 0);
    addfd(epollfd, server_sockfd);

    if(flag >= 0){
        printf("success connect!\n");
        while(!stop_flag){
            int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
            if(number < 0 && errno != EINTR){
                std::cout << "epoll failure" << std::endl;
                break;
            }
            for(int i = 0; i < number; ++i){
                int sockfd = events[i].data.fd;
                if(sockfd == 0 && events[i].events & EPOLLIN){
                    splice( 0, NULL, pipefd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
                    splice( pipefd[0], NULL, server_sockfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
                }else if((sockfd == server_sockfd) && (events[i].events & EPOLLIN)){ // this is not necessary because I redirect the std_out in server to client
                    memset(buf, '\0', BUFFER_SIZE);
                    ret = recv(server_sockfd, buf, BUFFER_SIZE, 0);
                    if(ret < 0){
                        if(errno != EAGAIN) printf("ERROR\n");
                        break; 
                    }else if(ret > 0){
                        printf("%s\n", buf);
                    } 
                }
            }
        }      
    }   

    close(epollfd);
    close(server_sockfd);
    return 0;
}