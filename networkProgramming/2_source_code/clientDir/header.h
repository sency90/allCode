#include <stdio.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 10001
#define BUFFER_SIZE 100

ssize_t readvn(int socketFD, char* buffer, size_t maxLength);
ssize_t writevn(int socketFD, char* buffer, size_t length);
ssize_t readn( int socketFD, char* buffer, size_t maxLength);
ssize_t writen( int fd, char *v, size_t n );
