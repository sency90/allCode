#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll power(ll x, ll n) {
    if(n==0LL) return 1LL;
    ll ret = power(x,n>>1);
    ret = ret*ret%MOD;
    if(n%2 == 1) ret=ret*x%MOD;
    return ret;
}
int main() {
    ll ans=0;
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        ll n,s; scanf("%lld%lld",&n,&s);
        ans = (ans + s*power(n,MOD-2))%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
