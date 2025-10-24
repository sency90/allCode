#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
bool fchk[101], gchk[101];
ll fdp[101], gdp[101];
ll f(int x) {
    if(x<=1) return 1;
    if(fchk[x]) return fdp[x];
    fchk[x] = true;

    return fdp[x] = (f(x-1)+f(x-2))%M;
}
ll g(int x) {
    if(x<=1) return x^1;
    if(gchk[x]) return gdp[x];
    gchk[x] = true;

    ll & ret = gdp[x];
    if(x%2==0) ret = (f(x)-f((x-1)/2)-f(x/2)+2*M)%M;
    else ret = (f(x)-f(x/2)+M)%M;
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        printf("%lld\n", g(n));
    }
    return 0;
}