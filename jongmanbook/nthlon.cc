#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int inf = 0x3f3f3f3f;
struct Edge{
    int t, w;
    Edge(){} Edge(int t, int w):t(t),w(w){}
    bool operator<(const Edge &rhs) const { return w > rhs.w; }
};
bool chk[401];
int dist[401];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        priority_queue<Edge> mnh;
        map<int, int> dif;
        int m,x,y;
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            if(!dif.count(x-y)) dif[x-y]=x;
            else if(dif[x-y]>x) dif[x-y]=x;
        }

        vector<vector<Edge> > v(401, vector<Edge>());
        for(auto &p : dif) {
            if(p.first >= 0) {
                for(int i=0; i+p.first<=400; i++) {
                    v[i].push_back(Edge(i+p.first, p.second));
                }
            } else {
                for(int i=400; i+p.first>=0; i--) {
                    v[i].push_back(Edge(i+p.first, p.second));
                }
            }
        }

        memset(chk, false, sizeof(chk));
        memset(dist, 0x3f, sizeof(dist));
        for(int i=0; i<v[200].size(); i++) {
            mnh.push(v[200][i]);
            dist[v[200][i].t] = v[200][i].w;
        }

        Edge ed;
        for(int i=0; i<=400; i++) {
            while(!mnh.empty()) {
                ed = mnh.top(); mnh.pop();
                if(!chk[ed.t]) break;
            }
            x = ed.t;
            chk[x] = true;

            for(auto &p : v[x]) {
                y=p.t;
                if(chk[y]) continue;
                if(dist[y] > ed.w + p.w) {
                    dist[y] = ed.w + p.w;
                    mnh.push(Edge(y, dist[y]));
                }
            }
        }
        if(dist[200] >= inf) puts("IMPOSSIBLE");
        else printf("%d\n", dist[200]);
    }
    return 0;
}
