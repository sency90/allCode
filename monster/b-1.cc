#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll,ll> > plii;
const ll inf = 0x3f3f3f3f3f3f3fLL;
ll cost[500001];
int chk[10001][10001];
int p[10001];
void init(ll n) {
    memset(p,0,sizeof(p));
    for(int i=0; i<=n; i++) p[i]=i;
}
ll find(ll x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(ll x, ll y) {
    if(x>y) swap(x,y);
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
        ll n,m,x,y,w;
        scanf("%lld%lld",&n,&m);
        memset(chk,0,sizeof(chk));
        memset(cost,0,sizeof(cost));
        vector<plii> ed;
        for(ll i=1; i<=m; i++) {
            scanf("%lld%lld%lld",&x,&y,&w);
            if(x==y||x<=0LL||y<=0LL||x>n||y>n) continue;
            if(x>y) swap(x,y);
            if(!chk[x][y]) {
                chk[x][y]=i;
                ed.push_back(make_pair(i,make_pair(x,y)));
            }
            cost[chk[x][y]]+=w;
        }
        sort(ed.begin(), ed.end(), cmp);

        ll ans = 0LL;
        memset(chk, 0, sizeof(chk));
        int q; scanf("%d", &q);
        for(ll i=0LL; i<q; i++) {
            int start,end; scanf("%d%d",&start,&end);
            if(start==end||start<=0||end<=0||start>n||end>n) continue;
            if(start>end) swap(start,end);
            if(chk[start][end]) continue;
            chk[start][end]=chk[end][start]=1;
            ll minc=inf;
            init(n);
            for(auto &t: ed) {
                ll idx=t.first;
                int x=t.second.first, y=t.second.second;
                if(uni(x,y)) minc = min(minc, cost[idx]);
                if(find(start)==find(end)) break;
            }
            if(find(start)==find(end)) ans+=minc;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
