#include <stdio.h>
const long long mod = 1000000007LL;

long long d[101][101][101];
long long f(int n, int l, int r){
    if(d[n][l][r]) return d[n][l][r];
    if(l<1 || r<1 || (l+r)>n+1) return 0LL;
    return d[n][l][r] = ((n-2)*f(n-1, l, r) + f(n-1, l-1, r) + f(n-1, l, r-1))%mod;
}

int main(){
    int n, r, l;
    d[1][1][1] = 1LL;
    scanf("%d %d %d", &n, &l, &r);
    printf("%lld", f(n, l, r));
    return 0;
}
