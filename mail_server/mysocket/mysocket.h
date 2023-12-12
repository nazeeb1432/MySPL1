#ifndef mysocket_H
#define mysocket_H
#define BUF 1024

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class MySocket
{

private:
    int create_socket, new_socket, size;
    socklen_t addrlen;
    char buffer[BUF];
    struct sockaddr_in address, cliaddress;
    void socketError(const char *errorMessage);

public:
    MySocket(int port);//server constructor, only port
    MySocket(const char *addr, int port);//client constructor, server Ip+port
    void createSocket();
    void bindSocket();
    void connectSocket();//for client
    void listenSocket();//for server
    int acceptNewConnection();
    const char *recvMessage(int socket = -1);//for the commands,SEND,LIST etc...
    void sendMessage(const char *message, int socket = -1);
    ~MySocket();
};
#endif