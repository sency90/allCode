//Prim Algorithm
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int t,w;
    Edge(){} Edge(int t, int w):t(t),w(w) {}
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};
bool chk[10001];
priority_queue<Edge> mnh;
vector<Edge> v[10001];
int main() {
    int n,m,s,e,w;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    Edge ed;
    mnh.push(Edge(1,0));
    int ans=0; for(int i=0; i<n; i++) {
        while(!mnh.empty()) {
            ed = mnh.top(); mnh.pop();
            if(!chk[ed.t]) break;
        }
        chk[ed.t] = true;
        ans += ed.w;
        for(auto &y : v[ed.t]) {
            if(chk[y.t]) continue;
            mnh.push(y);
        }
    }
    printf("%d", ans);
    return 0;
}
