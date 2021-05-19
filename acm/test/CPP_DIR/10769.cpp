#include <stdio.h>
#include <string.h>
#include <iostream>
int main() {
    char c, pc=0, ppc=0;
    int happy=0, sad=0;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(ppc==':' && pc=='-') {
            if(c==')') happy++;
            else if(c=='(') sad++;
        }
        ppc = pc;
        pc = c;
    }
    if(happy==0 && sad==0) puts("none");
    else if(happy > sad) puts("happy");
    else if(happy < sad) puts("sad");
    else puts("unsure");
    return 0;
}
