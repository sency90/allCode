#include <stdio.h>
#if 0
int main() {
    unsigned char c = 0xff;
    if(c == 0xff) printf("%x\n", c+1);
    else printf("%x\n", c-1);

    return 0;
}
#endif
#if 0
int main() {
    signed char c = 0xff;
    if(c=='\xff') printf("%x\n", c+1);
    else printf("%x\n", c-1);
    return 0;
}
#endif
#if 1
int main() {
    char c = 0xff;
    if(c==0xff) printf("%x\n", c+1);
    else {
        char *addr = &c;
        for(int i=0; i<4 ;i++) printf("[%x]: %#x\n", addr+i,*(addr+i));

        printf("%x\n", c);
        printf("%x\n", c-1);
    }
    return 0;
}
#endif
