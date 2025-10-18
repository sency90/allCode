#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
void Init(const string & s) {
    v.clear();
    v.resize(s.size()+1, vector<int>());
}
string s;
int MakeTree(int x) {
    int nx = x+1;
    if(s[x] == 'x') { //v[x]
        for(int i = 0; i < 4; i++) {
            v[x].push_back(nx);
            nx = MakeTree(nx);
        }
    }
    return nx;
}
int trans[] = {2,3,0,1};
void Dfs(int x) {
    printf("%c", s[x]);
    if(v[x].empty()) return;
    for(int i=0; i<4; i++) {
        int nx = v[x][trans[i]];
        Dfs(nx);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        Init(s);
        MakeTree(0);
        Dfs(0);
        puts("");
    }
    return 0;
}
