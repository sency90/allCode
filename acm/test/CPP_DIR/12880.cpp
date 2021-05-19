#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge{
    int s, e, w;
    Edge() {}
    Edge(int ss, int ee, int ww) {s=ss;e=ee;w=ww;}
    bool operator<(const Edge& rhs) const {
        return w > rhs.w;
    }
};
priority_queue<Edge> mnh;
bool chk[51], hasAns;
vector<pair<int,int> > v[51];
vector<int> u;

int n;
void dfs(int x, int cnt) {
    chk[x] = true;
    if(cnt==n) hasAns = true;
    if(hasAns) return;
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i].first]) continue;
        dfs(v[x][i].first, cnt+1);
    }
}

int main() {
    int x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&x);
            if(i!=j) mnh.push(Edge(i,j,x));
        }
    }

    Edge ed;
    int l=0, r=0;
    hasAns = false;
    while(!mnh.empty()) {
        if(!hasAns && r<=n) {
            ed = mnh.top(); mnh.pop();
            u.push_back(ed.s);
            v[ed.s].push_back(make_pair(ed.e,ed.w));
            r++;
        }

        hasAns = false;
        memset(chk, false, sizeof(chk));
        for(int i=l; i<u.size(); i++) {
            chk[u[i]] = true;
        }
        memset(chk, false, sizeof(chk));
        dfs(ed.s, 0);
        if(hasAns) {
            if(l==r && l==u.size()+n) break;
            l++;
        }
    }
    return 0;
}
