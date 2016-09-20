#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const long long inf = 1e18;
long long dist[1001], weight[10001];
bool chk[1001], zero[10001];
struct Edge{
    int t; long long w;
    Edge(){} Edge(int t, long long w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};
long long dijkstra(int s, int e, int n, vector<vector<Edge> >& v);
vector<vector<Edge> > a;
vector<pair<long long, long long> > ed;
int main() {
    int n,m,l,s,e;
    scanf("%d%d%d%d%d",&n,&m,&l,&s,&e);
    a.resize(n, vector<Edge>());
    long long u,v,w;
    for(int i=0; i<m; i++) {
        scanf("%lld%lld%lld",&u,&v,&w);
        a[u].push_back(Edge(v,i));
        a[v].push_back(Edge(u,i));
        ed.push_back(make_pair(u,v));
        if(!w) zero[i]=w=1LL;
        weight[i]=w;
    }
    long long best = dijkstra(s,e,n,a);
    for(int i=0; i<m; i++) {
        if(zero[i]) weight[i]=inf;
    }
    long long worst = dijkstra(s,e,n,a);

    if(best>l || worst<l) { puts("NO"); return 0; }

    puts("YES");
    if(worst>l) {
        for(int i=0; i<m; i++) {
            if(zero[i]) {
                weight[i]=1LL;
                long long d = dijkstra(s,e,n,a);
                if(d <= l) {
                    weight[i]+=(l-d);
                    break;
                }
            }
        }
    }

    for(int i=0; i<m; i++) printf("%lld %lld %lld\n",ed[i].first, ed[i].second, weight[i]);
    return 0;
}

long long dijkstra(int s, int e, int n, vector<vector<Edge> >& v) {
    priority_queue<Edge> mnh;
    memset(chk, false, sizeof(chk));
    memset(dist, 0x3f, sizeof(dist));
    dist[s]=0LL;
    mnh.push(Edge(s,0LL));

    Edge ed;
    for(int z=0; z<n; z++) {
        while(!mnh.empty()) {
            ed = mnh.top(); mnh.pop();
            if(!chk[ed.t]) break;
        }
        int x=ed.t;
        chk[x] = true;
        for(int i=0; i<v[x].size(); i++) {
            int y=v[x][i].t;
            long long w=weight[v[x][i].w];
            if(chk[y]) continue;
            if(dist[y] > ed.w + w) {
                dist[y] = ed.w + w;
                mnh.push(Edge(y,dist[y]));
            }
        }
    }
    return dist[e];
}
