#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
struct Edge{
    int e;
    long long tc;
    Edge(){} Edge(int e, long long tc):e(e),tc(tc) {}
    bool operator<(const Edge& rhs) const {
        return tc > rhs.tc;
    }
};
priority_queue<Edge> mnh;
vector<Edge> v[1001];
long long dist[100][1001];
int main() {
    int n,m,k,s,e;
    long long w;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++) {
        scanf("%d%d%lld",&s,&e,&w);
        v[s].push_back(Edge(e,w));
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0][1]=0LL;
    mnh.push(Edge(1,0LL));
    while(!mnh.empty()) {
        Edge ed = mnh.top(); mnh.pop();
        s = ed.e;
        if(dist[k-1][s] < ed.tc) continue;
        for(int i=0; i<v[s].size(); i++) {
            e=v[s][i].e; w=v[s][i].tc;
            long long d = dist[0][s] + w;
            if(d>=inf) continue;
            if(dist[0][e] > d) {
                swap(dist[0][e],d);
                mnh.push(Edge(e, dist[0][e]));
            }
            for(int j=1; j<k; j++) {
                if(d>=inf) break;
                if(dist[j-1][e] < d&&d < dist[j][e]) {
                    swap(dist[j][e],d);
                    mnh.push(Edge(e, dist[j][e]));
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(dist[k-1][i]<inf) printf("%lld\n", dist[k-1][i]);
        else puts("-1");
    }
    return 0;
}
