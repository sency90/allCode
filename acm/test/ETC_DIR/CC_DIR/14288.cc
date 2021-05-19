#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;
vector<int> v[100001];
int cnt=0;
struct Fenwick{
    int bit[100001];
    void add(int i, ll by) {
        for(;i<=cnt;i+=i&-i) bit[i]+=by;
    }
    ll sum(int i) {
        ll ret = 0ll;
        for(;i;i-=i&-i) ret+=bit[i];
        return ret;
    }
};
int ss[100001], ee[100001];
void dfs(int x) {
    ss[x]=++cnt;
    for(int y: v[x]) dfs(y);
    ee[x]=cnt;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        if(x<0) continue;
        v[x].push_back(i);
    }
    dfs(1);
    Fenwick fen[2];
    int cur=0;
    for(int i=0; i<m; i++) {
        int t,x,w;
        scanf("%d", &t);
        if(t==1) {
            scanf("%d%d",&x,&w);
            if(cur==0) {
                fen[0].add(ss[x],w);
                fen[0].add(ee[x]+1,-w);
            } else fen[1].add(ss[x],w);
        } else if(t==2) {
            scanf("%d",&x);
            ll ans = fen[0].sum(ss[x]) + fen[1].sum(ee[x])-fen[1].sum(ss[x]-1);
            printf("%lld\n", ans);
        } else cur^=1;
    }
    return 0;
}
