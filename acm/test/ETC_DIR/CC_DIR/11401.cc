#include <cstdio>
using namespace std;
typedef long long ll;
ll M = 1e9+7;
ll f(ll x, int y) {
    if(y==0) return 1LL;
    ll ret = f(x, y/2);
    ret *= ret;
    ret %= M;
    if(y%2==1) return ret*x%M;
    else return ret;
}
int main() {
    ll n,k; scanf("%lld%lld", &n,&k);
    ll a=1LL, b=1LL;
    for(ll i=n,j=1; j<=k; j++, i--) {
        a *= i; a %= M;
        b *= j; b %= M;
    }
    printf("%lld", a*f(b, M-2)%M);
    return 0;
}
