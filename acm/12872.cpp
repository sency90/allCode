#include <stdio.h>
const int MOD=1000000007;
int n, m, p, ans=0;
int main() {
    long long x = 1LL;
    scanf("%d%d%d",&n,&m,&p);
    for(long long i=1; i<=n; i++) {
        x*=i;
    }
    long long y = n-m+1;
    for(int i=0; i<=p; i++) {
        x*=y;
    }
    printf("%lld", x);
    return 0;
}
