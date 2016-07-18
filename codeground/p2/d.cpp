#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int dist[10001];
struct Edge{
    int n, w;
    Edge() {}
    Edge(int nn, int ww) {n=nn;w=ww;}
    bool operator<(const Edge& rhs) const {
        return w>rhs.w;
    }
};
bool chk[10001];
vector<vector<Edge> > v;
int main() {
    int testCase, n,m,s,e,w;
    scanf("%d", &testCase);
    for(int z=1; z<=testCase; z++) {
        scanf("%d%d",&n,&m);
        v.clear();
        v.resize(n+1);
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&s,&e,&w);
            v[s].push_back(Edge(e,w));
            v[e].push_back(Edge(s,w));
        }

        memset(chk, false, sizeof(chk));
        memset(dist, 0x3f, sizeof(dist));
        priority_queue<Edge> mnh;
        mnh.push(Edge(1,0));
        dist[1]=0;
        Edge ed;
        for(int i=0; i<n; i++) {
            while(!mnh.empty()) {
                ed=mnh.top(); mnh.pop();
                if(!chk[ed.n]) break;
            }
            chk[ed.n] = true;
            s = ed.n;
            for(int j=0; j<v[s].size(); j++) {
                e=v[s][j].n; w=v[s][j].w;
                if(chk[e]) continue;
                if(dist[e] > dist[s]+w) {
                    dist[e] = dist[s]+w;
                    mnh.push(Edge(e, dist[e]));
                }
            }
        }
        int sum=0;
        for(int i=1; i<=n; i++) {
            sum += dist[i];
        }
        printf("%d", sum);
    }
    return 0;
}
