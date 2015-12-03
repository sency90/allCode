#include "rw_vn.h"

ssize_t readn(int sockfd, char* buffer, size_t length) {
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = buffer;
    nleft = length;
    while(nleft > 0) {
        if((nread = read(sockfd, ptr, nleft)) < 0) {
            if(errno == EINTR) nread = 0; //handling interrupt
            else return -1; //error occurred when read() function has been finished abnormally.
        } else if(nread == 0) break; //handling EOF. If connection has been suddenly closed, read() function will return EOF, which is 0.

        nleft -= nread;
        ptr += nread;
    }

    return length-nleft;
}

ssize_t readvn(int sockfd, char* buffer, size_t length) {

    int reclen; //record length
    int rc;

    //retrieve the length of the record

    rc = readn(sockfd, (char*)&reclen, sizeof(int));
    if(rc != sizeof(int))
        return rc<0? -1:0;

    reclen = ntohl(reclen);

    if(reclen > length) { /* 헤더에 있던 메세지 길이 정보(reclen)가
                          parameter로 넘어온 명시된 길이(length)보다 크면,
                          일단 그냥 읽을 수는 없다.
                          그래서 어떻게든 처리를 해줘야 하는데,
                          여기에서는 그냥 error로 간주하고
                          일단 length길이만큼 읽은 다음에 나머지는 다 버려버리고
                          -1을 return 한다.
                          그리고 errno에 excessed message size(EMSGSIZE)라고 표시해준다.*/
        while(reclen > 0) {
            rc = readn(sockfd, buffer, length);
            if(rc!=length)
                return rc<0? -1:0;

            reclen -= length;
            if(reclen < length)
                length = reclen;
        }

        errno = EMSGSIZE;
        return -1;
    }

    //retrieve the record itself

    rc = readn(sockfd, buffer, reclen);
    if( rc != reclen )
        return rc<0? -1:0;

    return rc;
}








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
