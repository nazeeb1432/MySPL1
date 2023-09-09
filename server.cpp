#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

using namespace std;

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[]){

    if(argc<2){
        fprintf(stderr,"Port NO not provided.Program terminated\n");
        exit(1);
    }
    int sockfd,newsockfd,portno;
    char buffer[255];
    
    struct sockaddr_in serv_addr,cli_addr;
    socklen_t clilen;

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    if(sockfd<0)
    {
        error("Error opening socket.");
    }

    bzero((char *) &serv_addr,sizeof(serv_addr));//equivalent to memset
    portno=atoi(argv[1]);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(portno);

    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
        error("Binding failed.");
    }

    listen(sockfd,5);//5 connections





}