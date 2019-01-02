#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    if(n<=2 || n==12) puts("winter");
    else if(n>=3 && n<=5) puts("spring");
    else if(n>=6 && n<=8) puts("summer");
    else puts("fall");
    return 0;
}
