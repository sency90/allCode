#include <stdio.h>
//2, 3, 5, 9, 17
long long d[16];
long long f(int r, int x) {
    if(x==0) return 2;
    if(d[x]>0) return d[x];
    return d[x]=f(2*r,x-1)+r;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(1,n)*f(1,n));
    return 0;
}
