#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define RMOD 1000000007LL
using namespace std;
const long long MOD = 99999999999999997;
vector<int> v[2001];
long long d[2001];
long long r[2001][2001], src, sink;
long long three(int k) {
    if(d[k]>0) return d[k];
    if(k==0) return d[k]=1LL;
    if(k==1) return d[k]=3LL;
    long long ans = three(k/2);
    ans = ans*ans%MOD;
    if(k%2) ans=ans*3%MOD;
    return d[k] = ans;
}
bool chk[2001];
long long dfs(int x, long long mn) {
    if(chk[x]) return 0LL;
    chk[x] = true;
    if(x==sink) return mn;
    for(int i=0; i<v[x].size(); i++) {
        if(r[x][v[x][i]] <= 0LL) continue;
        long long f = dfs(v[x][i], min(mn, r[x][v[x][i]]));
        if(f) {
            r[x][v[x][i]] -= f;
            r[v[x][i]][x] += f;
            return f;
        }
    }
    return 0LL;
}
int main() {
    int n,m,s,e;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&s,&e);
        v[s].push_back(e);
        v[e].push_back(s);
        r[s][e]=r[e][s]=three(i);
    }
    src = 0; sink = n-1;
    long long ans = 0LL;
    while(true) {
        memset(chk, false, sizeof(chk));
        long long f = dfs(src, 0x3f3f3f3f);
        if(f==0) break;
        ans += f;
    }
    printf("%lld", ans%RMOD);
    return 0;
}
