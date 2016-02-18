#include <stdio.h>
int main() {
    char c, cnt=0;
    while((c=getchar())!='\n' && c!=EOF) {
        printf("%c", c);
        if((cnt%=10)++ == 9) printf("\n");
    }
    return 0;
}
