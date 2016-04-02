#include <stdio.h>
int main() {
    int t, n;
    char c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d ", &n);
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            for(int i=0; i<n; i++) putchar(c);
        }
        puts("");
    }
    return 0;
}
