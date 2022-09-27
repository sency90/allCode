#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k, dp[20020], a[20020];
int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++) {
        dp[i] = 1e15;
        ll x = a[i], y = a[i];
        for (ll j = i; j >= max(1LL, i - m + 1); j--) {
            x = max(x, a[j]);
            y = min(y, a[j]);
            dp[i] = min(dp[i], dp[j - 1] + k + (i - j + 1)*(x - y));
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
