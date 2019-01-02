#include <stdio.h>
typedef long long ll;
int main() {
    ll n; scanf("%lld", &n);
    n*=2;
    ll lo=1, hi=2e4;
    while(lo<=hi) {
        ll mid = (lo+hi)/2;
        if(mid*(mid+1)<n) lo = mid+1;
        else hi = mid-1;
    }
    printf("%lld", (hi+1)*(hi+2)/2);
    return 0;
}
