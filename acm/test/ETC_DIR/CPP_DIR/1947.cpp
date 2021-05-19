#include <stdio.h>
#define ll long long
const ll MOD = 1e+9;
ll a=0LL, b=1LL, c;
int main() {
    int n; scanf("%d", &n);
    for(int i=3; i<=n; i++) {
        c = (i-1)*(a+b)%MOD;
        a=b;b=c;
    }
    if(n==1) puts("0");
    else if(n==2) puts("1");
    else printf("%lld", c);
    return 0;
}
