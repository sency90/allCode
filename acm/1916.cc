#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[100001];
int dist[100001];
bool chk[100001];
priority_queue<pii,vector<pii>,greater<pii> > mxh;
int dijkstra(int s, int e, int n) {
    int x;
    memset(dist, 0x3f, sizeof(dist));
    mxh.push(make_pair(0,s)); chk[s]=true; dist[s]=0;
    for(int i=0; i<n-1; i++) {
        while(!mxh.empty()) {
            x=mxh.top().second; mxh.pop();
            if(!chk[x]) break;
        }
        chk[x]=true;
        for(auto &p: v[x]) {
            int y=p.second, w=p.first;
            if(chk[y]) continue;
            if(dist[y]>dist[x]+w) {
                dist[y]=dist[x]+w;
                mxh.push(make_pair(dist[y],y));
            }
        }
    }
    return dist[e];
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(make_pair(w,y));
    }
    int s,e;
    scanf("%d%d",&s,&e);
    printf("%d\n",dijkstra(s,e,n));
    return 0;
}
