#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bool chk[26][26], visited[26];
string s[1001];
vector<int> ans;
void dfs(int x) {
    visited[x] = true;
    for(int i=0; i<26; i++) {
        if(chk[x][i] && !visited[i]) dfs(i);
    }
    ans.push_back(x);
}
int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        ans.clear();
        memset(chk, false, sizeof(chk));
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s[i];
            if(i==0) continue;
            int j, lim = min(s[i].size(), s[i-1].size());
            for(j=0; j<lim; j++) {
                if(s[i-1][j] != s[i][j]) {
                    int pc=s[i-1][j]-'a', c=s[i][j]-'a';
                    chk[pc][c] = true;
                    break;
                }
            }
        }

        memset(visited, false, sizeof(visited));
        for(int i=0; i<26; i++) {
            if(!visited[i]) dfs(i);
        }

        reverse(ans.begin(), ans.end());
        bool hasAns = true;
        for(int i=0; i<26; i++) {
            for(int j=i+1; j<26; j++) {
                if(chk[ans[j]][ans[i]]) {
                    puts("INVALID HYPOTHESIS");
                    hasAns =false;
                    break;
                }
            }
            if(!hasAns) break;
        }
        if(!hasAns) continue;
        for(auto &p : ans) {
            printf("%c", p+'a');
        }
        puts("");
    }
    return 0;
}
