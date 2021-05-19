#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct Edge{
    int e, tc;
    Edge(){} Edge(int e, long long tc):e(e),tc(tc){}
    bool operator<(const Edge& rhs) const {
        return tc > rhs.tc;
    }
};
vector<priority_queue<int> > dist;
vector<vector<Edge> > v;
priority_queue<Edge> h;
int main() {
    int n,m,k,s,e,w,tc;
    scanf("%d%d%d",&n,&m,&k);
    v.resize(n, vector<Edge>());
    dist.resize(n, priority_queue<int>());
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&w);
        v[--s].push_back(Edge(--e,w));
    }
    dist[0].push(0);
    h.push(Edge(0,0));
    while(!h.empty()) {
        Edge ed = h.top(); h.pop();
        s = ed.e;
        if(dist[s].top() < ed.tc) continue;
        for(int i=0; i<v[s].size(); i++) {
            e=v[s][i].e; tc=ed.tc+v[s][i].tc;
            if(dist[e].size() < k) dist[e].push(tc);
            else if(tc < dist[e].top()) {
                dist[e].pop(); dist[e].push(tc);
            } else continue;
            h.push(Edge(e,tc));
        }
    }
    for(int i=0; i<n; i++) {
        if(dist[i].size()<k) puts("-1");
        else printf("%d\n",dist[i].top());
    }
    return 0;
}
