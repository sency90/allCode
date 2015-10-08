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
            if(errno == EINTR)
                nread = 0;
            else return -1;
        } else if(nread == 0) break;

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

    if(reclen > len) {
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
