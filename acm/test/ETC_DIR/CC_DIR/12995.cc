#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const long long MOD = 1e9+7LL;
vector<int> v[51], g[51];
long long d[51][51][51];
long long f(int root, int ch, int sel) {
    if(sel==0) return 1;
    else if(ch == v[root].size()) {
        if(sel==1) return 1;
        else return 0;
    }

    long long &ret = d[root][ch][sel];
    if(ret!=-1LL) return ret;
    else ret=0LL;

    int child = v[root][ch];
    for(int i=0; i<sel; i++) {
        ret += f(child,0,i) * f(root,ch+1,sel-i);
        if(ret >= MOD) ret%=MOD;
    }
    return ret;
}
void dfs(int x, int p) {
    for(auto &y : g[x]) {
        if(y == p) continue;
        v[x].push_back(y);
        dfs(y,x);
    }
}
int main() {
    int n,k,s,e;
    scanf("%d%d",&n,&k);
    memset(d, -1, sizeof d);
    for(int i=1; i<n; i++) {
        scanf("%d%d",&s,&e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    dfs(1,0);
    long long ans = 0LL;
    for(int i=1; i<=n; i++) {
        ans += f(i,0,k);
    }
    printf("%lld", ans%MOD);
    return 0;
}
