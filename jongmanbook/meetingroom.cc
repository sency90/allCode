#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Info{
    int x, y, idx;
    Info(){} Info(int x, int y, int idx) : x(x),y(y),idx(idx) {}
    bool operator<(const Info &rhs) const {
        if(y==rhs.y) {
            if(x==rhs.x) return idx <= rhs.idx;
            else return x < rhs.x;
        } else return y < rhs.y;
    }
};
vector<Info> v;
vector<int> ans, rans;
bool chk[202], hasAns;
int n, N;
void dfs(int x) {
    if(hasAns) return;
    chk[v[x].idx]=true;

    int i;
    for(i=x+1; i<N; i++) {
        if(v[x].y<=v[i].x && !chk[v[i].idx]) {
            ans.push_back(i);
            dfs(i);
            if(ans.size() == n && !hasAns) {
                hasAns = true;
                rans = ans;
            } else if(!ans.empty()) ans.pop_back();
            chk[v[i].idx] = false;
        }
    }
}
bool cmp(const int &lhs, const int &rhs) {
    return v[lhs].idx < v[rhs].idx;
}
int main() {
    int tc,x,y;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        N = 2*n;
        v.clear();
        for(int i=0; i<n; i++) {
            for(int j=0; j<2; j++) {
                scanf("%d%d",&x,&y);
                v.push_back(Info(x,y,i));
            }
        }
        hasAns = false;
        sort(v.begin(), v.end());
        for(int i=0; i<=n; i++) {
            memset(chk, false, sizeof(chk));
            ans.clear(); rans.clear(); ans.push_back(i);
            dfs(0);
            if(hasAns) {
                puts("POSSIBLE");
                sort(rans.begin(), rans.end(), cmp);
                for(auto &p : rans) {
                    printf("%d %d\n", v[p].x, v[p].y);
                }
                break;
            }
        }
        if(!hasAns) puts("IMPOSSIBLE");
    }
    return 0;
}
