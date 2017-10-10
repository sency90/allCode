#include <iostream>
using namespace std;

#define MAXN 5000
typedef long long ll;
const int MOD = 1e9+7;
int fact[MAXN+1], inv[MAXN+1];
int spow(int x, int k) {
    if(k==0) return 1;
    int ret = spow(x,k>>1);
    if(k&1) return (ll)ret*ret%MOD*x%MOD;
    else return (ll)ret*ret%MOD;
}

int C(int n, int k) {
    if(n<0||k<0||n<k) return 0;
    else return (ll)fact[n]*inv[n-k]%MOD*inv[k]%MOD;
}

inline int modinv(int x) { return spow(x, MOD-2); }
void init() {
    fact[0]=inv[0]=1;
    for(int i=1; i<=MAXN; i++) {
        fact[i] = (ll)fact[i-1]*i%MOD;
        inv[i] = modinv(fact[i]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int n,k; cin >> n >> k;
    cout << C(n,k) << "\n";
    return 0;
}
