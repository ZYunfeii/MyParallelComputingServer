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

#define MAX_EVENT_NUMBER 1024

int main (int argc, char** argv){
    int sockfd = atoi(argv[1]);
    int epollfd = atoi(argv[2]);

    bool stop_flag = false;

    epoll_event events[MAX_EVENT_NUMBER];
    char buf[1024];
    int ret = 0;

    printf("-------Hello client, Welcome to CGI server-------\n");
    printf("There are some choice for you:\n");
    printf("1\n");
    printf("2\n");
    printf("3\n");

    while(!stop_flag){
        printf("pp1\n");
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1); // -1: blocking until something happens
        printf("pp2\n");
        if(number < 0 && errno != EINTR){
            printf("epoll failure\n");
            break;
        }
        for(int i = 0; i < number; ++i){
            int fd = events[i].data.fd;
            if((fd == sockfd) && (events[i].events & EPOLLIN)){
                memset(buf, '\0', sizeof(buf));
                ret = recv(fd, buf, sizeof(buf), 0);
                if(ret < 0){
                    if(errno != EAGAIN) printf("ERROR\n");
                    break; 
                }else if(ret > 0){
                    printf("%s", buf);
                    // int choice = atoi(buf);
                    // std::cout<<choice<<std::endl;
                }else{
                    printf("null\n");
                }
            }
        }
    }   
    return 0;
}
