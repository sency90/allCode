#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
set<int> chk;
int n;
ll ans, d[22][22][2];
ll dfs(int pos, int prev, int big) {
    if(pos==0) {
        if(chk.size() == n) return 1LL;
        return 0LL;
    }
    ll &ret = d[pos][prev][big];
    if(ret!=-1LL) return ret;
    else ret=0LL;

    if(big) {
        for(int i=prev+1; i<=n; i++) {
            if(chk.count(i)) continue;
            chk.insert(i);
            ret += dfs(pos-1,i,big^1);
            chk.erase(i);
        }
    } else {
        for(int i=1; i<prev; i++) {
            if(chk.count(i)) continue;
            chk.insert(i);
            ret += dfs(pos-1,i,big^1);
            chk.erase(i);
        }
    }
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        memset(d,-1,sizeof(d));
        scanf("%d", &n);
        if(n==1) puts("1");
        else printf("%lld\n", dfs(n,0,1)+dfs(n,n+1,0));
    }
    return 0;
}
