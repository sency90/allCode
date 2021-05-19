#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int> > q;
struct Edge{
    int s, e, w;
    Edge(int _s, int _e, int _w) {
        s=_s; e=_e; w=_w;
    }
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};
vector<Edge> v[1001];
priority_queue<Edge> mnh;
bool chk[1001];
int co=0;
int main() {
    memset(chk, false, sizeof(chk));
    int n, m, x, y, w;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        v[x].push_back(Edge(x,y,w));
        v[y].push_back(Edge(y,x,w));
    }
    chk[1] = true;
    for(int i=0; i<v[1].size(); i++) {
        mnh.push(v[1][i]);
    }
    Edge tmp(0,0,0);
    for(int i=0; i<n-1; i++) {
        while(!mnh.empty()) {
            tmp = mnh.top(); mnh.pop();
            if(!chk[tmp.e]) break;
        }
        x = tmp.e;
        chk[x] = true;
        co += tmp.w;
        for(int j=0; j<v[x].size(); j++) {
            if(chk[v[x][j].e]) continue;
            mnh.push(v[x][j]);
        }
    }
    printf("%d", co);
    return 0;
}
