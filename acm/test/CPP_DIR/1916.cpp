#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Edge{
    int n, c;
    Edge() {}
    Edge(int nn, int cc) {n=nn;c=cc;}
    bool operator<(const Edge& rhs) const {
        return c > rhs.c;
    }
};
vector<Edge> v[1001];
priority_queue<Edge> mnh;
bool chk[1001];
int dist[1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x, y, w;
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(Edge(y,w));
    }

    int sn,en;
    scanf("%d%d",&sn,&en);
    memset(dist, 0x3f, sizeof(dist));
    dist[sn] = 0;
    mnh.push(Edge(sn,dist[sn]));

    Edge ed;
    int s, e, c;
    for(int i=0; i<n; i++) {
        while(!mnh.empty()) {
            ed = mnh.top(); mnh.pop();
            if(!chk[ed.n]) break;
        }
        s = ed.n;
        chk[s] = true;
        for(int j=0; j<v[s].size(); j++) {
            e = v[s][j].n;
            c = v[s][j].c;
            if(dist[e] > dist[s]+c) {
                dist[e] = dist[s]+c;
                mnh.push(Edge(e, dist[e]));
            }
        }
    }
    printf("%d\n", dist[en]);
    return 0;
}
