#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../headers/utils.h"
#include "../headers/shared.h"

#define BACKLOG 3

sig_atomic_t useless;
void sigChildHandler(int sig){
    wait(&useless);
}

int initSocketServer(int port, int backlog);

int main(int argc, char **argv){
    int port = DEFAULT_PORT;
    if(argv[1]){
        port = atoi(argv[1]);
    }

    struct sigaction action;
    action.sa_handler = sigChildHandler;
    ssigfillset(&action.sa_mask);
    action.sa_flags = SA_RESTART;
    int r = sigaction (signum, &action, NULL);
    checkNeg(r, "Error sigaction");
    
    int sockfd = initSocketServer(port, BACKLOG);
    
    int sock = saccept(sockfd);
    while(sfork()){
        sclose(sock);
        sock = saccept(sockfd);
    }

    sdup2(sock, STDIN_FILENO);
    sdup2(sock, STDOUT_FILENO);

    execl("/bin/bash", "bash", NULL);
    char error[] = "execl fail";
    swrite(sock, error, strlen(error));
    sclose(sock);
}

int initSocketServer(int port, int backlog){
    int sockfd = ssocket();
    sbind(port, sockfd);
    slisten(sockfd, backlog);
    return sockfd;
}
