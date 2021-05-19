#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
vector<int> v[2002];
int src,sink;
int r[2002][2002];
bool chk[2002][2002];
void mkedge(int x, int y, int w) {
    if(!chk[x][y]) {
        v[x].push_back(y);
        v[y].push_back(x);
    }
    chk[x][y]=chk[y][x]=true;
    r[x][y]+=w;
}
int level[2002];
queue<int> q;
int bfs(int src, int sink) {
    memset(level,-1,sizeof(level));
    level[src]=0;
    q.push(src);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int y: v[x]) {
            if(r[x][y]>0 && level[y]<0) {
                level[y]=level[x]+1;
                q.push(y);
            }
        }
    }
    return level[sink];
}
const int inf = 0x3f3f3f3f;
int work[2002];
int dfs(int x, int sink, int f) {
    if(x==sink) return f;
    for(int &i=work[x]; i<v[x].size(); i++) {
        int y=v[x][i];
        if(level[y]>level[x] && r[x][y]>0) {
            int flow = dfs(y,sink,min(f,r[x][y]));
            if(flow>0) {
                r[x][y]-=flow;
                r[y][x]+=flow;
                return flow;
            }
        }
    }
    return 0;
}
int dinic() {
    int flow=0;
    while(true) {
        if(bfs(src,sink)<0) return flow;
        int f=0;
        memset(work,0,sizeof(work));
        while((f=dfs(src,sink,inf))>0) flow+=f;
    }
}
int main() {
    int n,m; scanf("%d%d",&n,&m);
    src=0, sink=n+m+1;
    for(int i=1; i<=n; i++) {
        int k; scanf("%d",&k);
        mkedge(src,i,1);
        while(k--) {
            int x; scanf("%d", &x);
            mkedge(i,x+n,1);
        }
    }
    for(int i=1; i<=m; i++) mkedge(i+n,sink,1);

    int flow = dinic();
    printf("%d", flow);
    return 0;
}
