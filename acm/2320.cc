#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool chk[5][5], visited[17];
vector<int> ed[5], v[5][5];
int ans, cnt;
vector<string> s;
void dfs(int x, int cnt) {
    for(int p: v[x][x]) {
        if(visited[p]) continue;
        visited[p]=true;
        cnt+=s[p].size();
    }
    ans = max(ans, cnt);
    for(int y: ed[x]) {
        for(int p: v[x][y]) {
            if(visited[p]) continue;
            visited[p]=true;
            dfs(y, cnt+s[p].size());
            visited[p]=false;
        }
    }
}
inline int chg(char x) {
    if(x=='A') return 0;
    else if(x=='I') return 1;
    else if(x=='O') return 2;
    else if(x=='U') return 3;
    else return 4;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string t; cin >> t;
        s.push_back(t);
        int l = chg(s[i][0]), r=chg(s[i][s[i].size()-1]);
        if(!chk[l][r]) {
            chk[l][r]=true;
            ed[l].push_back(r);
        }
        v[l][r].push_back(i);
    }

    for(int i=0; i<5; i++) {
        cnt=0;
        dfs(i,0);
        memset(visited,false,sizeof(visited));
    }
    printf("%d\n", ans);
    return 0;
}
