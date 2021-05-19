#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge{
    int s, e, w;
    Edge(int ss, int ee, int ww) {
        s = ss; e = ee; w = ww;
    }
    bool operator<(const Edge& rhs) const {
        if(e==rhs.e) return s > rhs.s;
        else return e > rhs.e;
    }
};
priority_queue<Edge> mnh;
int cc[2001], mn;
int main() {
    int n, m, k, s, e, w, ans=0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++) {
        scanf("%d %d %d", &s, &e, &w);
        mnh.push(Edge(s,e,w));
    }
    for(int i=1; i<=n; i++) cc[i] = m;

    Edge tmp(0,0,0);
    while(!mnh.empty()) {
        tmp = mnh.top(); mnh.pop();
        mn = cc[tmp.s];
        for(int i=tmp.s+1; i<tmp.e; i++) {
            mn = min(mn, cc[i]);
        }
        if(mn-tmp.w>0) mn = tmp.w;
        for(int i=tmp.s; i<tmp.e; i++) {
            cc[i]-=mn;
        }
        ans+=mn;
    }
    printf("%d", ans);
    return 0;
}
