#include <cstdio>
using namespace std;
typedef long long ll;
int v[51];
int main() {
    ll n,l,r;
    scanf("%lld%lld%lld",&n,&l,&r);
    int i=0;
    while(n) {
        v[i++]=n%2;
        n/=2;
    }
    int lim = i;
    ll L=0, R=0;
    for(int i=lim, x=1; i>=1; i--, x++) {
        if(v[i-1]) {
            L+=ll(((l-1)+(1LL<<(x-1)))/(1LL<<x));
            R+=ll((r+(1LL<<(x-1)))/(1LL<<x));
        }
        //printf("%d: %lld %lld\n", i,L,R);
    }
    //printf("%lld %lld\n", L,R);
    printf("%lld\n", R-L);
    return 0;
}
