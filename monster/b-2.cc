#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int,int> > plii;
const ll inf = 0x3f3f3f3f3f3f3fLL;
ll cost[500001];
int chk[10001][10001];
int p[10001];
void init(int n) {
    memset(p,0,sizeof(p));
    for(int i=0; i<=n; i++) p[i]=i;
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else { p[y]=x; return true; }
}
bool cmp(const plii &lhs, const plii &rhs) {
    return cost[lhs.first]>cost[rhs.first];
}
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    while(tc--) {
        ll w;
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        memset(chk,0,sizeof(chk));
        memset(cost,0,sizeof(cost));
        vector<plii> ed;
        for(int i=1; i<=m; i++) {
            scanf("%d%d%lld",&x,&y,&w);
            if(x==y||x<=0||y<=0||x>n||y>n) continue;
            if(x>y) swap(x,y);
            if(!chk[x][y]) {
                chk[x][y]=i;
                ed.push_back(make_pair(i,make_pair(x,y)));
                cost[i]=w;
            } else cost[chk[x][y]]=min(cost[chk[x][y]],w);
        }
        sort(ed.begin(), ed.end(), cmp);

        ll ans = 0LL;
        memset(chk, 0, sizeof(chk));
        int q; scanf("%d", &q);
        for(int i=0; i<q; i++) {
            int start,end; scanf("%d%d",&start,&end);
            if(start==end||start<=0||end<=0||start>n||end>n) continue;
            if(start>end) swap(start,end);
            if(chk[start][end]) continue;
            chk[start][end]=chk[end][start]=1;
            ll minc=inf;
            init(n);
            for(auto &t: ed) {
                ll idx=t.first; x=t.second.first; y=t.second.second;
                if(p[start]==p[end]) break;
                if(uni(x,y)) minc = min(minc, cost[idx]);
            }
            ans+=minc;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
