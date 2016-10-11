#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> v[53];
int r[53][53],p[53],src,sink,ans;
int chg(char x) {
    if(isupper(x)) return x-'A'+26;
    else return x-'a';
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
        } r[s][e] += f;
    }

    const int inf = 0x3f3f3f3f;
    src = chg('A'), sink = chg('Z'), ans=0;
    while(true) {
        memset(p, -1, sizeof(p));
        queue<int> q; q.push(src); p[src] = src;
        while(!q.empty() && p[sink]==-1) {
            int x = q.front(); q.pop();
            for(auto &t : v[x]) {
                if(p[t]!=-1 || r[x][t]<=0) continue;
                p[t] = x; q.push(t);
            }
        }
        if(p[sink]==-1) break;
        int f = inf;
        for(int t=sink; t!=src; t=p[t]) f = min(f, r[p[t]][t]);
        for(int t=sink; t!=src; t=p[t]) {
            r[p[t]][t] -= f;
            r[t][p[t]] += f;
        } ans += f;
    }
    printf("%d", ans);
    return 0;
}

