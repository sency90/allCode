#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define i2 (i<<1)
#define j2 (j<<1)
using namespace std;
struct Edge{
    int x,y;
    Edge(){} Edge(int x, int y):x(x),y(y){}
    bool operator<(const Edge& rhs) const {
        if(y==rhs.y) return x<rhs.x;
        else return y<rhs.y;
    }
};
int r[202][202], p[202];
vector<Edge> v;
vector<vector<int> > g;
int L,W,N,D,src,sink,DD4;
const int inf = 0x3f3f3f3f;
inline void conn(int x, int y) {
    if(r[x][y]) return;
    g[x].push_back(y); r[x][y]=1;
    g[y].push_back(x);
}
bool overlap(int i, int j) {
    int dx=(v[i].x-v[j].x)*(v[i].x-v[j].x);
    int dy=(v[i].y-v[j].y)*(v[i].y-v[j].y);
    return dx+dy<=DD4;
}
int EdmondKarp() {
    int totalflow=0;
    while(true) {
        queue<int> q;
        memset(p, -1, sizeof(p));
        q.push(src); p[src]=src;
        while(!q.empty() && p[sink]==-1) {
            int x = q.front(); q.pop();
            for(auto &y: g[x]) {
                if(p[y]!=-1||r[x][y]<=0) continue;
                p[y]=x;
                q.push(y);
            }
        }
        if(p[sink]==-1) break;
        int mnf=inf;
        for(int i=sink; i!=src; i=p[i]) mnf=min(mnf,r[p[i]][i]);
        for(int i=sink; i!=src; i=p[i]) {
            r[p[i]][i]-=mnf;
            r[i][p[i]]+=mnf;
        }
        totalflow+=mnf;
    }
    return totalflow;
}
int main() {
    for(int z=1;;z++) {
        scanf("%d%d%d%d",&L,&W,&N,&D);
        if(L+W+N+D==0) return 0;
        v.clear();
        g.clear(); g.resize((N<<1)+2, vector<int>());
        memset(r,0,sizeof(r));
        DD4=D*D*4;
        src=N<<1, sink=(N<<1)|1;
        for(int i=0; i<N; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back(Edge(x,y));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            conn(i2,i2+1);
            if(v[i].y-D<=0) conn(src,i2);
            if(v[i].y+D>=W) conn(i2+1,sink);
            for(int j=i+1; j<v.size(); j++) {
                if(overlap(i,j)) {
                    conn(i2+1,j2);
                    //높이 순서가 0->2->1->3 형태로도 이어져 있을 수 있으므로,
                    //아래와 같이 반대로도 연결해야 한다.
                    conn(j2+1,i2);
                }
            }
        }
        printf("Case %d: %d\n",z,EdmondKarp());
    }
    return 0;
}
