#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct Edge{
    int e, tc;
    Edge(){} Edge(int e, int tc):e(e),tc(tc){}
    bool operator<(const Edge& rhs) const {
        return tc > rhs.tc;
    }
};
vector<priority_queue<int> > dist;
vector<vector<Edge> > v;
priority_queue<Edge> h;
int main() {
    int n,m,k=2,s,e,w,tc;
    scanf("%d%d",&n,&m);
    v.resize(n+1, vector<Edge>());
    dist.resize(n+1, priority_queue<int>());
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    dist[1].push(0);
    h.push(Edge(1,0));
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
    printf("%d\n", dist[n].top());
    return 0;
}
