#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAXN 5000
typedef long long ll;
const int MOD = 1e9+7;
int fact[MAXN+1], inv[MAXN+1];

ll spow(ll x, int k) {
    if(k==0) return 1LL;
    ll ret = spow(x, k>>1);
    if(k%2 == 0) return ret*ret%MOD;
    else return ret*ret%MOD*x%MOD;
}
inline ll modinv(ll x) { return spow(x,MOD-2); }
void init() {
    fact[0]=1;
    for(int i=1; i<=MAXN; i++) {
        fact[i] = (ll)fact[i-1] * i % MOD;
        inv[i] = modinv(fact[i]);
    }
}

ll C(int n, int k) {
    if(n<0 || k<0 || n<k) return 0LL;
    else return (ll)fact[n]*inv[n-k]%MOD*inv[k]%MOD;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int n, k;
    cin >> n >> k;
    printf("%lld\n", C(n,k));
    return 0;
}
