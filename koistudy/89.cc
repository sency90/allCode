#include <stdio.h>
typedef long long ll;
ll f(ll x, ll y) {
    if(y==0LL) return 1LL;
    ll ret = f(x,y/2);
    ret *= ret;
    if(y&1) return ret*x;
    else return ret;
}
int main() {
    ll a,r,n;
    scanf("%lld%lld%lld",&a,&r,&n);
    printf("%lld\n", a*f(r,n-1));
    return 0;
}
