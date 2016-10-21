#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge{
    int t,w;
    Edge(){} Edge(int t, int w):t(t),w(w){}
};

int in[10001],dist[10001];
queue<Edge> q;
vector<Edge> v[10001],g[10001];
vector<int> p[10001];

bool chk[10001];
int s,e;
void dfs(int x) {
    chk[x]=true;
    for(auto &y: v[x]) {
        g[x].push_back(y);
        in[y.t]++;
        if(chk[y.t]) continue;
        dfs(y.t);
    }
}
int tc=0;
void dfs2(int x) {
    chk[x]=true;
    for(auto &y: p[x]) {
        tc++;
        if(chk[y]) continue;
        dfs2(y);
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(Edge(y,w));
    }
    scanf("%d%d",&s,&e);
    dfs(s);

    memset(dist,0,sizeof(dist));
    q.push(Edge(s,0));
    while(!q.empty()) {
        Edge x=q.front(); q.pop();
        for(auto &y: g[x.t]) {
            if(dist[y.t]<dist[x.t]+y.w) {
                dist[y.t]=dist[x.t]+y.w;
                p[y.t].clear();
                p[y.t].push_back(x.t);
            } else if(dist[y.t]==dist[x.t]+y.w) {
                p[y.t].push_back(x.t);
            }
            if(--in[y.t]==0) q.push(y);
        }
    }

    memset(chk,false,sizeof(chk));
    dfs2(e);
    printf("%d\n%d\n",dist[e],tc);
    return 0;
}
