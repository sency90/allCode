#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int p[10001];
ll cost[500001];
int chk[10001][10001];
void init(int n) {
    for(int i=0; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    if(x>y) swap(x,y);
    x=find(x); y=find(y);
    if(x==y) return false;
    else { p[y]=x; return true; }
}
struct Edge{
    int s,e,idx;
    Edge(){} Edge(int s, int e, int idx):s(s),e(e),idx(idx){}
    bool operator<(const Edge& rhs) const{
        return cost[idx]>=cost[rhs.idx];
    }
};
ll MIN(ll x, ll y) { return x<y?x:y; }
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    while(tc--) {
        ll w; int n,m,x,y; scanf("%d%d",&n,&m);
        init(n);
        vector<Edge> ed;
        memset(cost, 0, sizeof(cost));
        memset(chk, 0, sizeof(chk));
        for(int i=1; i<=m; i++) {
            scanf("%d%d%lld",&x,&y,&w);
            if(x>y) swap(x,y);
            if(chk[x][y]==0) {
                ed.push_back(Edge(x,y,i));
                chk[x][y]=i;
            }
            cost[chk[x][y]]+=w;
        }

        memset(chk,0,sizeof(chk));
        sort(ed.begin(), ed.end());
        ll ans=0LL;
        int q,s,e; scanf("%d", &q);
        for(int i=0; i<q; i++) {
            init(n);
            scanf("%d%d",&s,&e);
            if(s==e) continue;
            if(s>e) swap(s,e);
            if(chk[s][e]) continue;
            chk[s][e]=1;
            ll mn=0x3f3f3f3f3f3f3fLL;
            for(auto &z: ed) {
                if(find(s)==find(e)) break;
                if(uni(z.s, z.e)) {
                    mn=MIN(mn,cost[z.idx]);
                }
            }
            ans+=mn;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
