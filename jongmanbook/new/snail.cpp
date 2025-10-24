#include <bits/stdc++.h>
using namespace std;
double dp[1001][1001];
bool chk[1001][1001];
double f(int n, int m) {
    if(m>=n) return 1;
    if(n==0 || m==0) return 0;
    if(chk[n][m]) return dp[n][m];

    chk[n][m] = true;
    double & ret = dp[n][m];
    return ret = f(n-1,m-1)*0.25 + f(n-2,m-1)*0.75;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        printf("%.8lf\n", f(n,m));
    }
    return 0;
}