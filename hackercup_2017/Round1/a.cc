#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll d[310][310], psum[310][310];
int v[310][310];
const ll inf = 0x3f3f3f3f3f3f3f3fULL;
int m;
ll f(int n, int r) {
    if(r<0) return inf;
    ll &ret = d[n][r];
    if(ret>=0) return ret;
    else ret=inf;
    if(n==0) return ret=(r==0)?0:inf;
    else if(r==0) return ret=0ll;
    int mn = min(m,r);
    for(int p=mn; p>=0; p--) {
        ret = min(ret, f(n-1,r-p)+psum[n][p]+p*p);
    }
    return ret;
}
int main() {
    freopen("./a_input.txt","r",stdin);
    freopen("./a_output.txt","w",stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        memset(d,-1,sizeof(d));
        memset(psum,0,sizeof(psum));
        memset(v,0,sizeof(v));
        int n; scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d",&v[i][j]);
            }
            sort(v[i]+1,v[i]+m+1);
            for(int j=1; j<=m; j++) {
                psum[i][j]=psum[i][j-1]+v[i][j];
            }

        }
        printf("Case #%d: %lld\n", z,f(n,n));
    }
    return 0;
}
