#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
struct Edge{
    int to;
    long long w;
    Edge(){} Edge(int to, long long w) : to(to), w(w) {}
    bool operator<(const Edge& rhs) const {return w > rhs.w;}
};
priority_queue<Edge> mnh;
vector<Edge> v[5001];
long long dist[5001], dist2[5001];
int main() {
    int n,r,s,e,w;
    scanf("%d%d",&n,&r);
    for(int i=0; i<r; i++) {
        scanf("%d %d %d",&s,&e,&w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    memset(dist, 0x7f, sizeof(dist));
    memset(dist2, 0x7f, sizeof(dist2));
    dist[1]=0;
    mnh.push(Edge(1,0));
    while(!mnh.empty()) {
        Edge ed = mnh.top(); mnh.pop();
        if(dist2[ed.to] < ed.w) continue;
        s = ed.to;
        for(int i=0; i<v[s].size(); i++) {
            e=v[s][i].to;
            long long d2=ed.w + v[s][i].w;
            if(dist[e] > d2) {
                swap(dist[e], d2);
                mnh.push(Edge(e,dist[e]));
            }
            if(dist[e] < d2&&d2 < dist2[e]) {
                dist2[e] = d2;
                mnh.push(Edge(e,dist2[e]));
            }
        }
    }
    printf("%lld\n", dist2[n]);
    return 0;
}
