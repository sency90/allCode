#include <stdio.h>
char s[101];
int main() {
    scanf("%s", s);
    int len=0; while(s[len]) len++;
    int t=0;
    for(int i=len-1; i>=0; i--) {
        t*=3;
        t+=(s[i]-'0');
    }
    printf("%d\n", t);
    return 0;
}
