#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct Edge{
    int e,w;
    Edge(int ee, int ww) {
        e = ee; w = ww;
    }
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};
priority_queue<Edge> mnh;
vector<Edge> v[10001];
bool chk[10001];
int main() {
    int V, E, s,e,w;
    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++) {
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    chk[1] = true;
    for(int i=0; i<v[1].size(); i++) {
        mnh.push(v[1][i]);
    }
    int cnt=1, ans=0;
    Edge tmp(0,0);
    while(!mnh.empty()) {
        tmp = mnh.top(); mnh.pop();
        if(chk[tmp.e]) continue;
        chk[tmp.e] = true;
        ans += tmp.w;
        if(++cnt >= V) break;
        for(int i=0; i<v[tmp.e].size(); i++) {
            if(chk[v[tmp.e][i].e]) continue;
            mnh.push(v[tmp.e][i]);
        }
    }
    printf("%d", ans);
    return 0;
}
