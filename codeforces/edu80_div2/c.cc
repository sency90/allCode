#include <cstdio>
using namespace std;
typedef long long ll;
ll d[1111][11];
ll mod = 1e9+7;
ll f(int n, int r) {
    if(r==0 || n==r) return d[n][r]=1LL;
    ll &ret = d[n][r];
    if(ret > 0LL) return ret;

    return ret = (f(n-1,r) + f(n-1,r-1)) % mod;
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    ll ans = 0LL;
    for(int i=1; i<=n; i++) {
        ans += f(i+(m-1)-1,m-1) * f((n-i+1)+m-1,m);
        ans %= mod;
    }
    printf("%lld", ans);
    return 0;
}
