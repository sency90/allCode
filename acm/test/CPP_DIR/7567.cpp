#include <stdio.h>
int main() {
    char c, prev=0;
    short res=0;
    while((c=getchar())!='\n' && c!=EOF) {
        if(prev == c) res+=5;
        else res+=10;
        prev = c;
    }
    printf("%d", res);
    return 0;
}
