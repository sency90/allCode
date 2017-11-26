#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int r[502][502];
bool chk[502][502];
vector<int> v[502];
const int inf = 0x3f3f3f3f;
void mkedge(int x, int y, int w) {
    if(!chk[x][y]) {
        v[x].push_back(y);
        v[y].push_back(x);
    }
    chk[x][y]=chk[y][x]=true;
    r[x][y]+=w;
}
queue<int> q;
int level[502];
bool bfs(int src, int sink) {
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
    return level[sink]>=0;
}
int work[502];
int dfs(int x, int sink, int f) {
    if(x==sink) return f;
    for(int &i=work[x]; i<v[x].size(); i++) {
        int y=v[x][i];
        if(level[y]>level[x] && r[x][y]>0) {
            int t = dfs(y,sink,min(f,r[x][y]));
            if(t>0) {
                r[x][y]-=t;
                r[y][x]+=t;
                return t;
            }
        }
    }
    return 0;
}
int dinic(int src, int sink) {
    int flow=0;
    while(bfs(src,sink)) {
        int f=0;
        memset(work,0,sizeof(work));
        while((f=dfs(src,sink,inf))>0) flow+=f;
    }
    return flow;
}
int main() {
    int n; scanf("%d", &n);
    int src=0, sink=n+1;
    for(int i=1; i<=n; i++) {
        int t; scanf("%d", &t);
        if(t==1) mkedge(src,i,inf);
        else if(t==2) mkedge(i,sink,inf);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int c; scanf("%d", &c);
            if(i==j) continue;
            mkedge(i,j,c);
        }
    }
    printf("%d\n", dinic(src,sink));
    for(int i=1; i<=n; i++) if(level[i]>=0) printf("%d ",i); puts("");
    for(int i=1; i<=n; i++) if(level[i]<0) printf("%d ", i); puts("");
    return 0;
}
