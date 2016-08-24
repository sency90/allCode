#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[53];
int r[53][53],src,sink,ans;
bool chk[53];
int chg(char x) {
    if(isupper(x)) return x-'A'+26;
    else return x-'a';
}
int dfs(int s, int mn) {
    if(chk[s]) return 0;
    chk[s] = true;

    if(s==sink) return mn;
    for(auto &p : v[s]) {
        if(chk[p]) continue;
        if(r[s][p] <= 0) continue;
        int flow = dfs(p, min(mn, r[s][p]));
        r[s][p]-=flow; r[p][s]+=flow;
        if(flow>0) return flow;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,f,s,e;
    char ss,ee;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >>ss>>ee>>f;
        s=chg(ss); e=chg(ee);
        if(!r[s][e] && !r[e][s]) {
            v[s].push_back(e);
            v[e].push_back(s);
        }
        r[s][e] += f;
    }

    const int inf = 0x3f3f3f3f;
    src = chg('A'), sink = chg('Z'), ans=0;
    while(true) {
        memset(chk, false, sizeof(chk));
        int flow = dfs(src, inf);
        ans += flow;
        if(flow == 0) break;
    }
    cout << ans;
    return 0;
}
