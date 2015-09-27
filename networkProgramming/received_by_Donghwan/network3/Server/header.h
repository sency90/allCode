#include<stdio.h>
#include<string.h>

#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>


#define PORT 8127
#define BUFFER_SIZE 1000
void echoClient(int serverSocketFD, const struct sockaddr* clientSocket,socklen_t clientSocketLength);

void echoServer(int serverSocketFD, const struct sockaddr* clientSocket,socklen_t clientSocketLength);
