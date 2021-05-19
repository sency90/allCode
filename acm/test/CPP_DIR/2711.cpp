#include <stdio.h>
int main() {
    int t, n;
    char s[81];
    scanf("%d", &t);
    while(t--) {
        scanf("%d ", &n);
        scanf("%s", s);
        s[n-1]='\0';
        printf("%s%s\n", s,s+n);
    }
    return 0;
}
