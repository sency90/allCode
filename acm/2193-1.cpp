#include <stdio.h>
long long d[91][2];
long long f(int n, int x) {
    if(d[n][x] > 0) return d[n][x];
    if(n==1) {
        if(x==1) return 1;
        else return 0;
    }
    if(x==0) d[n][x] = f(n-1,1-x)+f(n-1,x);
    else d[n][x] = f(n-1,1-x);
    return d[n][x];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n,0)+f(n,1));
    return 0;
}
