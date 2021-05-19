#include <stdio.h>
short d[1001] = {0,};
short f(short x) {
    if(x==0 || x==1) return 1;
    else if(d[x]==0) d[x] = (f(x-1) + f(x-2)) % 10007;
    return d[x];
}
int main() {
    short n; scanf("%hd", &n);
    printf("%hd\n", f(n));
    return 0;
}
