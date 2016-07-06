#include <stdio.h>
#define MOD 1000000007
long long d[1001][1001];
long long f(long long n, long long k) {
    if(n==k || k==0LL) return 1LL;
    if(d[n][k]>0) return d[n][k];
    return d[n][k] = (f(n-1,k-1)+f(n-1,k))%MOD;
}
int main() {
    int n;
    long long ans = 1LL, sum=0LL, d;
    scanf("%d%lld", &n,&d);
    sum+=d;
    for(int i=1; i<n; i++) {
        scanf("%lld", &d);
        ans = (ans*f(sum+(d-1),d-1))%MOD;
        sum += d;
    }
    printf("%lld", ans);
    return 0;
}
