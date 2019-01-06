#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
vector<int> v[200001];
int sum[200001],a[200001];
bool chk[200001];
bool bad = false;
void dfs(int x, int s) {
    if(bad) return;
    chk[x] = true;
    if(sum[x]!=-1 && s>sum[x]) {
        bad = true;
        return;
    }
    if(sum[x]==-1) a[x]=0;
    else a[x] = sum[x]-s;

    for(int y: v[x]) {
        if(!chk[y]) {
            dfs(y,max(s,sum[x]));
        }
    }
}
void dfsdfs(int x, int d) {
    chk[x] = true;
    if(d%2==0) {
        int mn = inf;
        for(int y: v[x]) {
            mn = min(mn,a[y]);
        }
        if(mn!=inf) a[x]=mn;

        for(int y: v[x]) {
            a[y]-=a[x];
            if(!chk[y]) {
                dfsdfs(y, d+1);
            }
        }
    } else {
        for(int y: v[x]) {
            if(!chk[y]) {
                dfsdfs(y, d+1);
            }
        }
    }
}
int main() {
    int n; scanf("%d", &n);
    for(int i=2; i<=n; i++) {
        int x; scanf("%d", &x);
        v[x].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &sum[i]);
    }

    dfs(1,0);
    if(bad) puts("-1");
    else {
        memset(chk,false,sizeof(chk));
        dfsdfs(1,1);
        ll ans=0;
        for(int i=1; i<=n; i++) ans+=a[i];
        printf("%lld\n", ans);
    }
    return 0;
}
