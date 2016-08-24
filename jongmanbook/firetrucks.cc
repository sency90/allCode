#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Edge{
    int t, w;
    Edge(){} Edge(int t, int w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};
vector<vector<Edge> > v;
vector<int> fire;
bool chk[1001];
int dist[1001];
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        priority_queue<Edge> mnh;
        int V,E,N,M,s,e,w;
        scanf("%d%d%d%d",&V,&E,&N,&M);
        fire.clear(); fire.resize(N,0);
        v.clear(); v.resize(V+1, vector<Edge>());
        for(int i=0; i<E; i++) {
            scanf("%d%d%d",&s,&e,&w);
            v[s].push_back(Edge(e,w));
            v[e].push_back(Edge(s,w));
        }

        memset(chk, false, sizeof(chk));
        memset(dist, 0x3f, sizeof(dist));
        int station;
        for(int i=0; i<N; i++) {
            scanf("%d", &fire[i]);
        }
        for(int i=0; i<M; i++) {
            scanf("%d", &station);
            mnh.push(Edge(station, 0));
            dist[station]=0;
        }
        mnh.push(Edge(0,0));

        chk[0] = true;
        Edge ed;
        for(int i=0; i<V+1; i++) {
            while(!mnh.empty()) {
                ed = mnh.top(); mnh.pop();
                if(dist[ed.t] < ed.w) continue;
                if(!chk[ed.t]) break;
            }
            s = ed.t;
            chk[s] = true;
            for(int j=0; j<v[s].size(); j++) {
                e=v[s][j].t; w=v[s][j].w;
                if(chk[e]) continue;
                if(dist[e] > w+ed.w) {
                    dist[e] = w+ed.w;
                    mnh.push(Edge(e, dist[e]));
                }
            }
        }
        int ans = 0;
        for(int i=0; i<fire.size(); i++) {
            ans += dist[fire[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}
