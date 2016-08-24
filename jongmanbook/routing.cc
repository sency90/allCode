#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge{
    int t;
    double w;
    Edge(){} Edge(int t, long double w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};
vector<vector<Edge> > v;
priority_queue<Edge> mnh;
bool chk[10001];
double dist[10001];
const double inf = 0x3f3f3f3f;
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,x,y;
        double w;
        scanf("%d%d", &n,&m);
        v.clear();
        v.resize(n, vector<Edge>());
        for(int i=0; i<m; i++) {
            scanf("%d%d%lf",&x,&y,&w);
            v[x].push_back(Edge(y,log10(w)));
            v[y].push_back(Edge(x,log10(w)));
        }

        memset(chk, false, sizeof(chk));
        for(int i=0; i<n; i++) dist[i] = inf;
        chk[0] = true;
        for(int i=0; i<v[0].size(); i++) {
            mnh.push(v[0][i]);
            dist[v[0][i].t] = v[0][i].w;
        }

        Edge ed;
        for(int i=1; i<n; i++) {
            while(!mnh.empty()) {
                ed = mnh.top(); mnh.pop();
                if(dist[ed.t] < ed.w) continue;
                if(!chk[ed.t]) break;
            }
            chk[ed.t] = true;
            x = ed.t;
            for(int j=0; j<v[x].size(); j++) {
                y = v[x][j].t; w = v[x][j].w;
                if(chk[y]) continue;
                if(dist[y] > w+dist[x]) {
                    dist[y] = w+dist[x];
                    mnh.push(Edge(y, dist[y]));
                }
            }
        }
        printf("%0.10lf\n", pow(10,dist[n-1]));
    }
    return 0;
}
