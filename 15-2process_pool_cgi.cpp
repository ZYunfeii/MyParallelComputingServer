#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>

#include "15-1processpool.h"

class cgi_coon{
public:
    cgi_coon(){}
    ~cgi_coon(){}
    void init(int epollfd, int sockfd, const sockaddr_in& client_addr){
        m_epollfd = epollfd;
        m_sockfd = sockfd;
        m_address = client_addr;
        memset(m_buf, '\0', BUFFER_SIZE);
        m_read_idx = 0; // mark the next position of the last byte of user data that has been read in the read buffer
    }

    void process(){
        int ret = 0;
        while(1){
            memset(m_buf, '\0', BUFFER_SIZE);
            ret = recv(m_sockfd, m_buf, BUFFER_SIZE, 0);
            if(ret < 0){
                if(errno != EAGAIN) removefd(m_epollfd, m_sockfd);
                break; 
            }else{
                if(ret > 0){
                    printf("user content is: %s\n", m_buf);
                    // char* file_name = m_buf;
                    // std::cout<<ret<<std::endl;
                    char* file_name = (char*)"/home/yunfei/MyProject/MyCGIServer/CGI";
                    if(access(file_name, F_OK) == -1){
                        std::cout<<"point2"<<std::endl;
                        removefd(m_epollfd, m_sockfd);
                        break;
                    }
                    ret = fork(); // !!
                    if(ret == -1){
                        std::cout<<"point3"<<std::endl;
                        removefd(m_epollfd, m_sockfd);
                        break;
                    }else if(ret > 0){
                        std::cout<<"point4"<<std::endl;
                        removefd(m_epollfd, m_sockfd);
                        break;
                    }else{
                        std::cout<<"point5"<<std::endl;
                        close(STDOUT_FILENO);
                        dup(m_sockfd);

                        char fd[128];
                        char epfd[128];
                        sprintf(fd, "%d", m_sockfd);
                        sprintf(epfd, "%d", m_epollfd);                        
                        execl(file_name, file_name, fd, epfd, (char*)0);     

                        const char* msg_send = "The CGI does not run!";               
                        exit(0);
                    }
                }else printf("no receive");
            }
        }
    }

private:
    static const int BUFFER_SIZE = 1024;
    static int m_epollfd;
    int m_sockfd;
    sockaddr_in m_address;
    char m_buf[BUFFER_SIZE];
    int m_read_idx;
};

int cgi_coon::m_epollfd = -1;

int main(int argc, char** argv){
    if(argc <= 2){
        printf("usage:%s ip_address port_number\n", basename(argv[0]));
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    ret = bind(listenfd, (struct sockaddr*)& address, sizeof(address));
    assert(ret != -1);

    ret = listen(listenfd, 5);
    assert(ret != -1);

    processpool<cgi_coon>* pool = processpool<cgi_coon>::create(listenfd);
    if(pool){
        pool->run();
        delete pool;
    }
    close(listenfd);
    


    return 0;
}