#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int fact[5001], inv[5001];
const int MOD = 998244353;
int spow(int x, int k) {
    if(k==0) return 1;
    ll ret = spow(x,k>>1);
    if(k&1) return ret*ret%MOD*x%MOD;
    else return ret*ret%MOD;
}
inline int modinv(int x) { return spow(x,MOD-2); }
void init() {
    fact[0]=inv[0]=1;
    for(int i=1; i<=5000; i++) {
        fact[i] = (ll)fact[i-1]*i%MOD;
        inv[i] = modinv(fact[i]);
    }
}
ll C(int n, int k) {
    if(n<0||k<0||n<k) return 0LL;
    return (ll)fact[n]*inv[n-k]%MOD*inv[k]%MOD;
}
ll resA, resB, resC;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int a,b,c; cin >>a>>b>>c;
    int mx = max({a,b,c});
    for(int i=0; i<=mx; i++) {
        if(i<=a && i<=b) resA+=C(a,i)*C(b,i)%MOD*fact[i]%MOD, resA%=MOD;
        if(i<=b && i<=c) resB+=C(b,i)*C(c,i)%MOD*fact[i]%MOD, resB%=MOD;
        if(i<=c && i<=a) resC+=C(c,i)*C(a,i)%MOD*fact[i]%MOD, resC%=MOD;
    }
    cout << resA*resB%MOD*resC%MOD;
    return 0;
}
