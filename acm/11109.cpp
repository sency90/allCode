#include <stdio.h>
int main() {
    int t, n, a, b, r;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d %d %d %d", &n, &r, &a, &b);
        a = r*a;
        b = r*b+n;
        if(a>b) puts("parallelize");
        else if(a<b) puts("do not parallelize");
        else puts("does not matter");
    }
    return 0;
}
