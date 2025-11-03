#include <bits/stdc++.h>
using namespace std;
int dp[201][201];
const int INF = 0x3f3f3f3f;
int combi(int n, int r) {
    if(n == r || r == 0) return 1;
    else if(r<0 || n<r) return 0;
    int & ret = dp[n][r];
    if(ret>0) return dp[n][r];
    return ret = min(INF, combi(n - 1, r - 1) + combi(n - 1, r));
}
string f(int n, int m, int k) {
    if(n == 0 && m == 0) return "";
    int combs = combi(n + m - 1, n - 1);
    if(combs >= k) return "-" + f(n - 1, m, k);
    else return "o" + f(n, m - 1, k - combs);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        printf("%s\n", f(n, m, k).c_str());
    }
    return 0;
}