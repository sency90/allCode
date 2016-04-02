#include <stdio.h>
#include <vector>
#include <cstring>
#define INF 100000001
using namespace std;
struct Edge{
    int e, w;
    Edge(int ee, int ww) {
        e = ee; w = ww;
    }
};
bool chk[801];
int d[801];
vector<Edge> v[801];
int main() {
    int n, m, s, e, w, p, q, mn, x, cost[2]={0,0};
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    scanf("%d %d", &p, &q);
    int id=0, c[]={1,p,q,1,q,p}, f[]={p,q,n,q,p,n};
    while(id<6) {
        for(int i=1; i<=n; i++) d[i] = INF;
        memset(chk, false, sizeof(chk));
        d[c[id]]=0;
        for(int i=1; i<n; i++) {
            mn = INF+1;
            for(int j=1; j<=n; j++) {
                if(!chk[j] && mn > d[j]) {
                    mn = d[j];
                    x = j;
                }
            }
            chk[x]=true;
            for(int j=0; j<v[x].size(); j++) {
                if(d[v[x][j].e] > d[x]+v[x][j].w) {
                    d[v[x][j].e] = d[x]+v[x][j].w;
                }
            }
        }
        if(d[f[id]]>INF) {
            id = (id/3+1)*3;
            cost[id/3] = INF;
        }
        cost[id/3]+=d[f[id]];
        id++;
    }
    if(cost[0]>=INF && cost[1]>=INF) puts("-1");
    else if(cost[0]>cost[1]) printf("%d", cost[1]);
    else printf("%d", cost[0]);
}
