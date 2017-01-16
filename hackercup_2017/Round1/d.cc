#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll d[2001];
int r[2001];
ll mm(ll x) {
    if(x>=mod) return x%mod;
    else return x;
}
ll fact(ll n) {
    ll &ret = d[n];
    if(ret) return ret;
    if(n==0) return ret=1ll;
    else return ret = mm(n*fact(n-1));
}
map<int, map<int,ll>> com;
ll combi(int n, int r) {
    if(n==r||r==0) return 1ll;
    if(com.count(n)) {
        if(com[n].count(r)) {
            return com[n][r];
        }
    }
    return com[n][r] = mm(combi(n-1,r-1)+combi(n-1,r));
}
int main() {
    freopen("./d_input.txt", "r", stdin);
    freopen("./d_output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        memset(r,0,sizeof(r));
        int n,m,sum=0;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d", &r[i]);
            sum+=r[i]*2;
        }

        if(n==1) printf("Case #%d: %d\n", z,m);
        else {
            ll ans=0ll;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(i==j) continue;
                    int board = m-1+r[i]+r[j];
                    int g = board-sum;
                    if(g<0) continue;
                    ans = mm(ans + combi(n+g,min(n,g))*fact(n-2));
                }
            }
            printf("Case #%d: %lld\n",z,ans);
        }
    }
    return 0;
}
