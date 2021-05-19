#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> v;
vector<pair<pii,int>> ed;
int r[51][51], p[51];
const int inf = 0x3f3f3f3f;
int netflow(int n, int src, int snk) {
    int ans=0;
    while(true) {
        memset(p, -1, sizeof(p));
        queue<int> q;
        q.push(src); p[src]=src;
        while(!q.empty() && p[snk]==-1) {
            int x = q.front(); q.pop();
            for(int y: v[x]) {
                if(p[y]==-1 && r[x][y]>0) {
                    p[y]=x;
                    q.push(y);
                }
            }
        }
        if(p[snk]==-1) return ans;
        int mnf = inf;
        for(int i=snk; i!=src; i=p[i]) mnf=min(mnf,r[p[i]][i]);
        for(int i=snk; i!=src; i=p[i]) {
            r[p[i]][i]-=mnf;
            r[i][p[i]]+=mnf;
        }
        ans+=mnf;
    }
    return ans;
}
int sum, mn=inf;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        ed.push_back({{x,y},w});
        sum+=x;
    }
    int s,e; scanf("%d%d",&s,&e);
    for(int i=0; i<m; i++) {
        v.clear(); v.resize(n+1);
        memset(r,0,sizeof(r));
        for(int j=0; j<m; j++) {
            if(i==j) continue;
            int x=ed[j].first.first, y=ed[j].first.second, w=ed[j].second;
            if(!r[x][y] && !r[y][x]) {
                v[x].push_back(y);
                v[y].push_back(x);
            }
            r[x][y]=r[y][x]=w;
        }
        mn = min(mn,netflow(n,s,e));
    }
    printf("%d", sum-mn);
    return 0;
}
