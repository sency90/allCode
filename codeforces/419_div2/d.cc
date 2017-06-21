#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll fact[200001], invf[200001];
vector<ll> v[2];
const ll mod = 1e9+7LL;
ll bino(int x, int y) {
    return fact[x]*(invf[x-y]*invf[y]%mod) % mod;
}
ll spow(int x, int p) {
    if(p==0) return 1LL;
    ll ret = spow(x,p>>1);
    ret=ret*ret%mod;
    if(p&1) return ret*x%mod;
    else return ret;
}
int main() {
    ll n; scanf("%lld", &n);
    for(int i=0; i<n; i++) {
        ll x;
        scanf("%lld", &x);
        v[0].push_back(x);
    }
    fact[0]=invf[0]=1LL;
    for(ll i=1LL; i<=n; i++) {
        fact[i]=fact[i-1]*i%mod;
        invf[i]=spow(fact[i],mod-2);
    }
    int t=0;
    for(int plus=1; n%4!=1; t^=1,n--) {
        for(int i=0; i<n-1; i++) {
            if(plus) v[t^1].push_back(v[t][i]+v[t][i+1]);
            else v[t^1].push_back(v[t][i]-v[t][i+1]+mod);
            v[t^1][i]%=mod;
            plus^=1;
        }
        v[t].clear();
    }
    ll ans=0LL;
    int N = n>>1;
    for(int i=0; i<n; i+=2) {
        ans += bino(N,i>>1)*v[t][i];
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
