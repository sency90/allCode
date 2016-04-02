#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct Edge{
    int e, w;
    Edge(int ee, int ww) {
        e = ee; w = ww;
    }
    bool operator< (const Edge &rhs) const {
        return w > rhs.w;
    }
};
priority_queue<Edge> mnh;
vector<Edge> ed[20001];
int chk[20001], inf=25000, d[20001];
int main() {
    int v, e, k, a, b, c, x, y, mn;
    scanf("%d %d %d",&v,&e,&k);
    for(int i=0; i<e; i++) {
        scanf("%d %d %d", &a,&b,&c);
        ed[a].push_back(Edge(b,c));
    }
    memset(chk, false, sizeof(chk));
    for(int i=1; i<=v; i++) d[i] = inf;
    d[k]=0;
    Edge to = Edge(k,0);
    mnh.push(to);
    for(int i=1; i<v; i++) {
        while(!mnh.empty()) {
            to = mnh.top(); mnh.pop();
            if(!chk[to.e]) break;
        }
        chk[to.e] = true;
        for(int j=0; j<ed[to.e].size(); j++) {
            y = ed[to.e][j].e;
            if(d[y] > d[to.e] + ed[to.e][j].w) {
                d[y] = d[to.e] + ed[to.e][j].w;
                mnh.push(Edge(y,d[y]));
            }
        }
    }
    for(int i=1; i<=v; i++) {
        if(d[i]>=inf) puts("INF");
        else printf("%d\n", d[i]);
    }
}
