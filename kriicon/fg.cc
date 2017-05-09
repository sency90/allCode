#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7LL;
ll spow(ll x, ll n) {
    if(n==0) return 1LL;
    ll ret = spow(x,n>>1);
    if(n&1) ret=ret*ret*x;
    else ret=ret*ret;
    if(ret>=mod) return ret%mod;
    else return ret;
}
int main() {
    ll n, ans=1LL; scanf("%lld", &n);
    for(ll i=0LL; i<n; i++) {
        ans*=spow(i,(i>>1)+1);
        if(ans>=mod) ans%=mod;
    }
    printf("%lld\n", ans);
    return 0;
}
