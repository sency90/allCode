#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll diff[100001], dp[100001][2];
ll ABS(ll x) { return x<0LL?-x:x; }
int main() {
    int n; scanf("%d", &n);

    ll x,px=0;
    for(int i=0; i<n; i++) {
        scanf("%lld", &x);
        if(i>0) diff[i-1] = ABS(x-px);
        px = x;
    }

    ll ans=-0x3f3f3f3f;
    for(int i=0; i<n-1; i++) {
        dp[i][0] = max(dp[i-1][1]+diff[i], diff[i]);
        dp[i][1] = max(dp[i-1][0]-diff[i], -diff[i]);
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    printf("%lld\n", ans);
    return 0;
}
