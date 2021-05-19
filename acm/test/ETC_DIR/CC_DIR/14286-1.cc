#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<int> v[503];
int r[503][503],p[503],src,sink,ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x,y,f;
        cin >>x>>y>>f;
        if(!r[x][y] && !r[y][x]) {
            v[x].push_back(y);
            v[y].push_back(x);
        } r[x][y] += f;
        r[y][x]=r[x][y];
    }
    cin >>src>>sink;

    const int inf = 0x3f3f3f3f;
    ans=0;
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

