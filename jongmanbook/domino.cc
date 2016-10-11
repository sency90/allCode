#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    ll n; scanf("%lld",&n);
    ll sum=0LL;
    for(ll i=0; i<=n; i++) {
        for(ll j=i; j<=n; j++) {
            sum+=i+j;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
