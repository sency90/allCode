#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int e, w;
    Edge(){} Edge(int e, int w):e(e),w(w) {}
    bool operator<(const Edge& rhs) const {
        return w > rhs.w;
    }
};
priority_queue<Edge> h;
vector<Edge> v[1001];
priority_queue<int> dist[1001];
int main() {
    int n,m,k,s,e,w;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&w);
        v[s].push_back(Edge(e,w));
    }
    dist[1].push(0);
    h.push(Edge(1,0));
    while(!h.empty()) {
        Edge ed = h.top(); h.pop();
        s = ed.e;
        if(dist[s].top() < ed.w) continue;
        for(int i=0; i<v[s].size(); i++) {
            e = v[s][i].e; w = ed.w + v[s][i].w;
            if(dist[e].size() < k) dist[e].push(w);
            else if(w < dist[e].top()) {
                dist[e].pop();
                dist[e].push(w);
            } else continue;
            h.push(Edge(e,w));
        }
    }
    for(int i=1; i<=n; i++) {
        if(dist[i].size() < k) puts("-1");
        else printf("%d\n", dist[i].top());
    }
    return 0;
}
