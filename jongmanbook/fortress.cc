#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Castle{
    int x, y, r, idx;
    Castle(){} Castle(int x, int y, int r) : x(x),y(y),r(r) {}
    bool operator<(const Castle &rhs) const {
        return r < rhs.r;
    }
};
vector<Castle> v;
bool everRoot[1001], chk[1001];
vector<int> cc[1001];
int mx, mxidx;
bool isInclude(const Castle &co, const Castle &ci) {
    if((co.x-ci.x)*(co.x-ci.x) + (co.y-ci.y)*(co.y-ci.y) <= co.r*co.r) return true;
    else return false;
}
void connect(const Castle &co, const Castle &ci) {
    cc[ci.idx].push_back(co.idx);
    cc[co.idx].push_back(ci.idx);
}
void dfs(int x, int cnt) {
    chk[x] = true;
    if(mx < cnt) {
        mxidx = x;
        mx = cnt;
    }
    for(int i=0; i<cc[x].size(); i++) {
        if(chk[cc[x][i]]) continue;
        dfs(cc[x][i], cnt+1);
    }
}
int main() {
    int t,n,x,y,r;
    scanf("%d", &t);
    while(t--) {
        memset(everRoot, false, sizeof(everRoot));
        scanf("%d", &n);
        v.clear();
        for(int i=0; i<n; i++) {
            scanf("%d %d %d",&x,&y,&r);
            v.push_back(Castle(x,y,r));
            cc[i].clear();
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++) v[i].idx = i;
        int f = 0;
        vector<Castle> c[2];
        c[f].push_back(v[0]);
        for(int i=1; i<v.size(); i++) {
            bool everInclude = false;
            for(auto &p : c[f]) {
                if(isInclude(v[i], p)) {
                    connect(v[i], p);
                    if(!everRoot[i]) {
                        c[f^1].push_back(v[i]);
                        everRoot[i] = true;
                    }
                    everInclude = true;
                } else c[f^1].push_back(p);
            }
            if(!everInclude) c[f^1].push_back(v[i]);
            c[f].clear();
            f^=1;
        }
        memset(chk, false, sizeof(chk));
        mx=0; mxidx=0;
        dfs(1,0);
        memset(chk, false, sizeof(chk));
        mx=0;
        dfs(mxidx,0);
        printf("%d\n", mx);
    }
    return 0;
}
