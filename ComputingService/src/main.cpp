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
#include <cmath>
#include "myInv.h"

#define MAX_EVENT_NUMBER 1024
#define MAX_BUFFER_SIZE 1024

static int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

static void addfd( int epollfd, int fd ) // add file desc into the epollfd pool
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}

void calInv(char* buf){

    std::vector<double> src;
    for(int i = 0; i < MAX_BUFFER_SIZE; ++i){
        if(buf[i] == ' ' || buf[i] == '\r') continue;
        if(buf[i+1] == '\0') break;
        src.push_back((double)(buf[i] - '0'));
    }

    std::vector<double> res = myInv(src);

    std::cout << "The inverse matrix is:" << std::endl;
    int N = std::sqrt(res.size());
    for (int i = 0; i < res.size(); ++i) {
        if(i % N == 0 && i > 0) std::cout<<"\n";
        std::cout<<res[i]<<" ";
	}
    std::cout<<std::endl;
}

std::string transform(char* buf){
    std::string tmp = "";
    for(int i = 0; i < MAX_BUFFER_SIZE; ++i){
        if(buf[i] == ' ' || buf[i] == '\r') continue;
        if(buf[i+1] == '\0') break;
        tmp += buf[i];
    }
    return tmp;
}

int main (int argc, char** argv){
    int sockfd = atoi(argv[1]);
    int epollfd = atoi(argv[2]);
    
    addfd(epollfd, sockfd);

    bool stop_flag = false;

    epoll_event events[MAX_EVENT_NUMBER];
    char buf[MAX_BUFFER_SIZE];
    int ret = 0;

    std::cout << "-------Hello client, Welcome to Computing Server-------" << std::endl;
    std::cout << "-------This Server can calculate the inverse matrix:" << std::endl;
    std::cout << "-------If you want to calculate [1 2;3 4], please input: 1 2 3 4" <<  std::endl;
    std::cout << "-------Enter \"stop\" to Esc." << std::endl;


    while(!stop_flag){
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1); // -1: blocking until something happens
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
                    if(transform(buf) == "stop") stop_flag = true;
                    else calInv(buf);
                }else{
                    printf("null\n");
                }
            }
        }
    }

    std::cout << "Srv Ends" << std::endl;   
    return 0;
}
