#include <bits/stdc++.h>
using namespace std;
int price[21], like[21];
int n, m;
const int MASK = (1 << 16) - 1;
int dp[MASK + 1];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        m /= 100;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            cin >> price[i] >> like[i];
            price[i] /= 100;
        }
        for(int i = 0; i <= m; i++) {
            int& result = dp[i & MASK];
            for(int j = 0; j < n; j++) {
                if(i - price[j] >= 0) {
                    result = max(result, dp[(i - price[j]) & MASK] + like[j]);
                }
            }
        }

        printf("%d\n", dp[m & MASK]);
    }
    return 0;
}