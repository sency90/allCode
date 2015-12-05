#ifndef RW_VN_H
#define RW_VN_H

#include <errno.h> //for "errono" variable
#include <sys/types.h> //for size_t, ssize_t types
#include <unistd.h> //for read(), write() functions
#include <netinet/in.h> //for htons(), htonl(), ntohs(), ntohl() functions
#include <stdio.h>


ssize_t readn(int sockfd, char* buffer, size_t length);
ssize_t readvn(int sockfd, char* buffer, size_t length);
ssize_t writen(int sockfd, char* buffer, size_t length);
ssize_t writevn(int sockfd, char* buffer, size_t length);

#endif
