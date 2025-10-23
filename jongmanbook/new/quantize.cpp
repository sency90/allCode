#include <bits/stdc++.h>
using namespace std;
int v[101];
int dp[101][11];
bool chk[101][11];
const int INF = 0x3f3f3f3f;
int lp[101][101];
int GetMinSqSum(int b, int e) {
    if(b == e) return 0;
    int& ret = lp[b][e];
    if(ret >= 0) return ret;

    ret = INF;
    for(int i = v[b]; i <= v[e]; i++) {
        int sum = 0;
        for(int j = b; j <= e; j++) {
            sum += (v[j] - i) * (v[j] - i);
        }
        ret = min(ret, sum);
    }
    return ret;
}
int f(int x, int s) {
    if(x == 0 && s >= 0)
        return 0;
    else if(s < 0)
        return INF;

    int& ret = dp[x][s];
    if(chk[x][s]) return ret;
    chk[x][s] = true;

    if(s == 1) return ret = GetMinSqSum(1, x);

    ret = INF;
    for(int i = x; i >= 1; i--) {
        ret = min(ret, GetMinSqSum(i, x) + f(i - 1, s - 1));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, s;
        cin >> n >> s;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v + 1, v + n + 1);
        memset(chk, false, sizeof(chk));
        memset(lp, -1, sizeof(lp));

        printf("%d\n", f(n, s));
    }

    return 0;
}