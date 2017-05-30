#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll d[101][101];
const ll mod = (ll)1e9+7LL;
int main() {
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    d[0][0]=1;
    for(int i=1; i<=p; i++) {
        for(int j=1; j<=p; j++) {
            d[i][j] += ((j-m)>0)?(j-m)*d[i-1][j]%mod:0LL;
            d[i][j] += (n-(j-1)>0)?(n-(j-1))*d[i-1][j-1]%mod:0LL;
            d[i][j]%=mod;
        }
    }
    ll ans=0ll;
    for(int i=n; i<=p; i++) ans += d[p][i];
    printf("%lld\n", ans%mod);
    return 0;
}
