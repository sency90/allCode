#include <stdio.h>
#include <ctype.h>
int main() {
    int t;
    char c;
    scanf("%d ", &t);
    while(t--) {
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(isupper(c)) c+=32;
            printf("%c", c);
        } printf("\n");
    } return 0;
}
