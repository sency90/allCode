#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e7;
bool chk[101][101];
ll dp[101][101];
int f(int x, int r) {
    if(x==r) return 1;
    if(chk[x][r]) return dp[x][r];
    chk[x][r] = true;
    ll & ret = dp[x][r];

    for(int i=1; i<=x-r; i++) {
        ret += (ll)(i+r-1)*f(x - r, i);
        ret %= M;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll ans=0;
        for(int i=1; i<=n; i++) {
            ans += f(n,i);
            ans %= M;
        }
        printf("%lld\n", ans);
    }
    return 0;
}