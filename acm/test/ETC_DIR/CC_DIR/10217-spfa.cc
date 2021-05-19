#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int v,c,d;
    Edge(){}
    Edge(int v, int c, int d):v(v),c(c),d(d){}
};
vector<vector<int>> dist;
vector<vector<Edge>> ed;
queue<Edge> q;
const int inf = 0x3f3f3f3f;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m,k;
        scanf("%d%d%d", &n,&m,&k);
        dist.clear(); dist.resize(n+1, vector<int>(m+1, inf));
        ed.clear(); ed.resize(n+1, vector<Edge>());
        for(int i=0; i<k; i++) {
            int u,v,c,d;
            scanf("%d%d%d%d",&u,&v,&c,&d);
            ed[u].emplace_back(v,c,d);
        }

        dist[1][0] = 0;
        q.emplace(1,0,0);
        while(!q.empty()) {
            Edge s = q.front(); q.pop();
            if(dist[s.v][s.c] < s.d) continue;
            dist[s.v][s.c] = s.d;

            for(Edge &e : ed[s.v]) {
                if(s.c+e.c>m) continue;
                if(dist[e.v][s.c+e.c]<=s.d+e.d) continue;
                for(int i=s.c+e.c; i<=m; i++) {
                    if(dist[e.v][i] > s.d+e.d) {
                        dist[e.v][i] = s.d+e.d;
                    } else break;
                }
                q.emplace(e.v, s.c+e.c, s.d+e.d);
            }
        }

        if(dist[n][m]!=inf) printf("%d\n", dist[n][m]);
        else puts("Poor KCM");
    }
    return 0;
}
