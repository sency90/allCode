#include <stdio.h>
int main() {
    char c;
    while(scanf(" %c", &c)!=EOF) {
        if(c=='q') break;
        printf("%c\n", c);
    }
    puts("q");
    return 0;
}
