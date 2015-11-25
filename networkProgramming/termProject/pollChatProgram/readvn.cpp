#include "header.h"
#include <errno.h>

ssize_t readn(int fd, char* vptr, size_t n) {
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = vptr;
    nleft = n;
    while(nleft > 0) {
        if((nread = read(fd, ptr, nleft)) < 0) {
            if(errno == EINTR) nread = 0; //handling interrupt
            else return -1; //error occurred when read() function has been finished abnormally.
        } else if(nread == 0) break; //handling EOF. If connection has been suddenly closed, read() function will return EOF, which is 0.

        nleft -= nread;
        ptr += nread;
    }

    return n-nleft;
}

ssize_t readvn(int fd, char* buffer, size_t len) {

    int reclen; //record length
    int rc;

    //retrieve the length of the record

    rc = readn(fd, (char*)&reclen, sizeof(int));
    if(rc != sizeof(int))
        return rc<0? -1:0;

    reclen = ntohl(reclen);

    if(reclen > len) { /* 헤더에 있던 메세지 길이 정보(reclen)가
                          parameter로 넘어온 명시된 길이(len)보다 크면,
                          일단 그냥 읽을 수는 없다.
                          그래서 어떻게든 처리를 해줘야 하는데,
                          여기에서는 그냥 error로 간주하고
                          일단 len길이만큼 읽은 다음에 나머지는 다 버려버리고
                          -1을 return 한다.
                          그리고 errno에 excessed message size(EMSGSIZE)라고 표시해준다.*/
        while(reclen > 0) {
            rc = readn(fd, buffer, len);
            if(rc!=len)
                return rc<0? -1:0;

            reclen -= len;
            if(reclen < len)
                len = reclen;
        }

        errno = EMSGSIZE;
        return -1;
    }

    //retrieve the record itself

    rc = readn(fd, buffer, reclen);
    if( rc != reclen )
        return rc<0? -1:0;

    return rc;
}

ssize_t readln(int fd, char*buffer, size_t len) {
    ssize_t n, rc;
    char c, *ptr;

    ptr = buffer;
    for(n=1; n<len; n++) {
        //again:
        if((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if(c == '\n') break; //newline is stored
        }
        else if(rc == 0) {
            if(n == 1) {
                return 0;
            }
            else break;

        }
        else {
            if(errno == EINTR) {
                --n;
                continue;
                //goto again;
            }
            return -1;
        }
    } //end of for-loop?
}
