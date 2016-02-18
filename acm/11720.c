#include <stdio.h>
int main() {
    short s=0,c;
    while((c=getchar())&48);
    while((c=getchar())&48)s+=c-48;
    printf("%hd",s);
    return 0;
}
