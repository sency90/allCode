#include <stdio.h>
int main() {
    int n, a=0, b=0;
    char s[16];
    scanf("%d ", &n);
    scanf("%s", s);
    for(int i=0; i<n; i++) {
        if(s[i]=='A') a++;
        else b++;
    }
    if(a>b) puts("A");
    else if(a==b) puts("Tie");
    else puts("B");
}
