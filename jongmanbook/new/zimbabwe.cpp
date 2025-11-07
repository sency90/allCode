#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
string e, d;
int m, n, fullchk;
inline bool IsChk(int chkbit, int i) { return (chkbit >> i) & 1; }
inline void TogChk(int& chkbit, int i) { chkbit ^= (1 << i); }
const int M = 1e9 + 7;
int dp[20][1 << 16][2];
int dfs(int idx, int rmd, int chkbit, int is_less) {
    if(chkbit == fullchk) {
        if(rmd == 0 && is_less) {
            return dp[rmd][chkbit][is_less] = 1;
        }
        return dp[rmd][chkbit][is_less] = 0;
    }

    int& ret = dp[rmd][chkbit][is_less];
    if(ret >= 0) return ret;

    ret = 0;
    int q = rmd * 10;
    bool is_same = !is_less;
    for(int i = 0; i < d.size(); i++) {
        if(IsChk(chkbit, i)) continue;
        if(i > 0 && d[i - 1] == d[i] && !IsChk(chkbit, i - 1)) continue; // 이 조건이 중요하다.
        if(is_same && d[i] > e[idx]) continue;

        TogChk(chkbit, i);
        q += d[i] - '0';
        ret += dfs(idx + 1, q % m, chkbit, (d[i] < e[idx]) | is_less);
        if(ret >= M) ret -= M;
        q -= d[i] - '0';
        TogChk(chkbit, i);
    }
    return ret;
}
int main() {
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> e >> m;
        d = e;
        fullchk = (1 << e.size()) - 1;
        sort(d.begin(), d.end());
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, 0, 0, 0));
    }
    return 0;
}