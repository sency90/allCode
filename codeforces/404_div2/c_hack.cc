#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(m>=n-2) printf("%lld\n", n);
    else {
        double p;
        ll l=8*(n-m)-3;
        p = sqrt(l)-3.0;
        p = p/2.0;
        ll k=ceil(p);
        printf("%lld\n", m+1+k);
    }
    return 0;
}
