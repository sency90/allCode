#include <cstdio>
#include <algorithm>
using namespace std;
int t[16], p[16], dp[21];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&t[i], &p[i]);
    }
    int mx = 0;
    for(int i=1; i<=n; i++) {
        mx = max(mx, dp[i]);
        dp[i+t[i]] = max(dp[i+t[i]], mx+p[i]);
    }
    mx = 0;
    for(int i=1; i<=n+1; i++) {
        mx = max(mx, dp[i]);
    }
    printf("%d\n", mx);
    return 0;
}
