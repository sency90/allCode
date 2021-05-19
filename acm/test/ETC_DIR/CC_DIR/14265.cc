#include <cstdio>
using namespace std;
typedef long long ll;
ll get(ll k, ll x, ll even) {
    if(x<0||k>x) return 0;
    if(k==0) return x+1;

    for(ll i=0,ret=0;;ret+=(1ll<<(i++ +even))) {
        if(k*(1ll<<i)<=x && x<k*(1ll<<(i+1))) {
            ll r = x-k*(1ll<<i)+1ll;
            if(r<=(1ll<<(i+even))) return ret+r;
            else return ret+(1ll<<(i+even));
        }
    }
    return 0ll;
}
int main() {
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    printf("%lld\n", get(k,b,!(k&1)) - get(k,a-1,!(k&1)));
    return 0;
}
