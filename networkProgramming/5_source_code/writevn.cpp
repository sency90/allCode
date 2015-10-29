//writevn.cpp
#include "header.h"

ssize_t writen(int sockfd, char* buffer, size_t length) {
    /********/
    //writen 함수를 완성하시오
    /********/

    size_t nleft;
    ssize_t nwritten;
    char *ptr;

    ptr = buffer;
    nleft = length;
    while(nleft > 0) {
        if(( nwritten = write(sockfd, ptr, nleft )) <= 0 ) {
            if(errno == EINTR) {
                nwritten = 0; //call write again
            } else {
                return -1; // error occurred.
            }
        }

        nleft -= nwritten;
        ptr += nwritten;
    }

    return length-nleft; // return >= 0;
}


ssize_t writevn(int sockfd, char* buffer, size_t length) {
    ssize_t nwritten;
    size_t tempBuffer = htonl(length);

    //First, write the part of the variable-length message header
    nwritten = writen(sockfd, (char*)&tempBuffer, sizeof(int));

    //Second, write the other part which is the variable data
    writen(sockfd, buffer, length);

    return nwritten;
}
