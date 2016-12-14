#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[200001], b[200001], am[200001];
vector<ll> bm;
int main() {
    ll n;
    int m,k;
    scanf("%lld%d%d",&n,&m,&k);
    bm.resize(k);

    ll x,s;
    scanf("%lld%lld",&x,&s);
    for(int i=1; i<=m; i++) scanf("%lld",&a[i]);
    for(int i=1; i<=m; i++) scanf("%lld",&am[i]);
    for(int i=0; i<k; i++) scanf("%lld",&b[i]);
    for(int i=0; i<k; i++) scanf("%lld",&bm[i]);
    ll mn=n*x;
    ll rmana;
    a[0]=x; am[0]=0;
    for(int i=0; i<=m; i++) {
        //printf("%lld\n", mn);
        rmana=s-am[i];
        if(rmana<0) continue;
        auto it = upper_bound(bm.begin(),bm.end(),rmana);
        //printf("%lld\n", rmana);
        if(it==bm.begin()) {
            mn=min(mn,n*a[i]);
        } else {
            it--;
            int j=it-bm.begin();
            //printf("remainder: %lld ", n-b[j]);
            if(n-b[j]<=0) return 0&puts("0");
            mn=min(mn,(n-b[j])*a[i]);
            //printf("mn: %lld\n", mn);
        }
    }
    printf("%lld\n", mn);
    return 0;
}
