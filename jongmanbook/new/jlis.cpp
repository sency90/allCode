#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
long long v[2][101];
int f(int x, int y) {
    if(x + y <= 1) return x + y;
    int& ret = dp[x][y];
    if(ret) return ret;

    ret = 1;
    if(v[0][x] > v[1][y]) {
        for(int i = 0; i < x; i++) {
            if(v[0][i] < v[0][x]) {
                ret = max(ret, f(i, y) + 1);
            }
        }
    } else if(v[0][x] < v[1][y]) {
        for(int i = 0; i < y; i++) {
            if(v[1][i] < v[1][y]) {
                ret = max(ret, f(x, i) + 1);
            }
        }
    } else {
        long long tmp = v[0][x];
        for(int i = 0; i < x; i++) {
            if(v[0][i] < tmp) {
                ret = max(ret, f(i, y));
            }
        }
        for(int i = 0; i < y; i++) {
            if(v[1][i] < tmp) {
                ret = max(ret, f(x, i));
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> v[0][i];
        for(int i = 1; i <= m; i++) cin >> v[1][i];
        v[0][0]=v[1][0] = -0x3f3f3f3f3f3f3f3fLL;

        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                ans = max(ans, f(i, j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}