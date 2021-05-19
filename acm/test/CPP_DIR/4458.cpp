#include <stdio.h>
#include <ctype.h>
int main() {
    int n;
    char c;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        c=getchar();
        if(islower(c)) putchar(c-'a'+'A');
        else putchar(c);
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            putchar(c);
        }
        puts("");
    }
    return 0;
}
