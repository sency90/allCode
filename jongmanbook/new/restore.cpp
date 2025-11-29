#include <bits/stdc++.h>
using namespace std;
string org_s[16], s[16];
int dp[16][1 << 16];
int overlap[16][16];
bool del[16];
int N;
const int INF = 0x3f3f3f3f;
vector<vector<vector<int>>> v;
int f(int n, int bit) {
    if(bit == 0) return s[n].size();
    int& ret = dp[n][bit];
    if(ret) return ret;

    ret = INF;
    for(int i = 0; i < N; i++) {
        if((bit >> i) & 1) {
            int res = f(i, bit ^ (1 << i)) + s[n].size() - overlap[i][n];
            if(ret > res) {
                ret = res;
                v[n][bit].clear();
                v[n][bit].push_back(i);
            } else if(ret == res) {
                v[n][bit].push_back(i);
            }
        }
    }
    return ret;
}
string dfs(int n, int bit) {
    if(bit == 0) return s[n];
    for(int i = 0; i < v[n][bit].size(); i++) {
        int y = v[n][bit][i];
        if(bit & (1 << y)) {
            string ans = dfs(y, bit ^ (1 << y));
            if(ans.empty()) continue;

            return ans + s[n].substr(overlap[y][n]);
        }
    }
    return s[n];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> org_s[i];
        }

        // 완전히 포함하는 case를 지운다.
        memset(del, false, sizeof(del));
        for(int i = 0; i < n; i++) {
            if(del[i]) continue;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < org_s[i].size(); k++) {
                    if(strncmp(org_s[i].c_str() + k, org_s[j].c_str(), org_s[j].size()) == 0) {
                        del[j] = true;
                    }
                }
            }
        }

        N = 0;
        for(int i = 0; i < n; i++) {
            if(!del[i]) s[N++] = org_s[i];
        }

        memset(overlap, 0, sizeof(overlap));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j) continue;
                for(int k = 0; k < s[i].size(); k++) {
                    if(strncmp(s[i].c_str() + k, s[j].c_str(), s[i].size() - k) == 0) {
                        overlap[i][j] = s[i].size() - k;
                        break;
                    }
                }
            }
        }
        s[N++] = "";

        memset(dp, 0, sizeof(dp));
        v.clear();
        v.resize(N + 1, vector<vector<int>>(1 << N, vector<int>()));
        f(N - 1, (1 << (N - 1)) - 1);

        printf("%s\n", dfs(N - 1, (1 << N - 1) - 1).c_str());
    }

    return 0;
}
