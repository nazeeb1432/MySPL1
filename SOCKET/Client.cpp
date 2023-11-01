/*
filename server_ipadress portno

argv[0] filename
argv[1] server_ipadress
argv[2] portno

*/

#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>//for read/write/close
#include<netdb.h>

using namespace std;

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[]){

    int sockfd,portno,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[255];
    if(argc<3){
        fprintf(stderr,"usage %s hostname port\n",argv[0]);
        exit(1);
    }

    portno=atoi(argv[2]);
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
        error("ERROR opening socket");
    }

    server=gethostbyname(argv[1]);//gets the server ip address

    if(server==NULL){
        fprintf(stderr,"Error,no such host");
    }

    bzero((char*) &serv_addr , sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char *)server->h_addr , (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port=htons(portno);

    if(connect(sockfd, (struct sockaddr *) &serv_addr , sizeof(serv_addr))<0)
            error("Connection Failed");
    
    bzero(buffer,255);

    FILE *f;
    int words=0;

    char c;

    f=fopen("glad.txt", "r");

    while((c=getc(f))!=EOF){
        fscanf(f,"%s",buffer);
        if(isspace(c) || c=='\t') words++;
    }

    write(sockfd,&words,sizeof(int));//server will read this
    rewind(f);

    char ch;
    while(ch!=EOF){
        fscanf(f,"%s",buffer);
        write(sockfd,buffer,255);
        ch=fgetc(f);
    }
    printf("The file has been successfully sent.Thank you\n");

    close(sockfd);


    return 0;

}