//Undirected Graph
//Dijkstra Algorithm using binary heap
//O((E+V)lgV)

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const long long inf = 1e18;
struct Edge{
    int t; long long w;
    Edge(){} Edge(int t, long long w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};

vector<vector<Edge> > ed;
vector<long long> dist;
vector<bool> chk;

//dijkstra(start, end, number of verties, adj matrix);
long long dijkstra(int s, int e, int n, vector<vector<Edge> >& v) {
    priority_queue<Edge> mnh;
    chk.clear(); chk.resize(n, false);
    dist.clear(); dist.resize(n, inf);
    dist[s]=0LL;
    mnh.push(Edge(s,dist[s]));

    Edge ed;
    for(int z=0; z<n; z++) {
        while(!mnh.empty()) {
            ed = mnh.top(); mnh.pop();
            if(!chk[ed.t]) break;
        }
        int x=ed.t;
        chk[x] = true;
        for(int i=0; i<v[x].size(); i++) {
            int y = v[x][i].t;
            long long D = ed.w + v[x][i].w;
            if(chk[y]) continue;
            if(dist[y] > D) {
                dist[y] = D;
                mnh.push(Edge(y,dist[y]));
            }
        }
    }
    return dist[e];
}

int main() {
    int n,m,s,e;
    scanf("%d%d",&n,&m); //n: number of verties, m: number of edges
    scanf("%d%d",&s,&e); //s: start, e: end
    ed.clear(); ed.resize(n, vector<Edge>());
    long long u,v,w;
    for(int i=0; i<m; i++) {
        scanf("%lld%lld%lld",&u,&v,&w);
        ed[u].push_back(Edge(v,w));
        ed[v].push_back(Edge(u,w));
    }
    printf("%lld", dijkstra(s,e,n,ed));
    return 0;
}

