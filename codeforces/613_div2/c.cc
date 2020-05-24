#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
inline ll gcd(ll b, ll s) {
    return (s==0LL)?b:gcd(s, b%s);
}
int main() {
    ll mn=0x3f3f3f3f3f3f3f3fLL,a=0,b=0;
    ll n; scanf("%lld", &n);
    for(ll i=1; i*i<=n; i++) {
        if(n%i == 0) {
            ll j=n/i;
            if(gcd(i,j) == 1LL) {
                if(max(i,j) < mn) {
                    mn = max(i,j);
                    a=i; b=j;
                }
            }
        }
    }
    printf("%lld %lld\n", a,b);
    return 0;
}
