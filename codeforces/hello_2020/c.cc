#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
ll f[250001];
int main() {
    ll n,m;
    scanf("%lld %lld",&n,&m);
    f[0] = 1LL;
    for(int i=1; i<=n; i++) {
        f[i] = f[i-1]*i%m;
    }
    ll ret = 0LL;
    for(int i=1; i<=n; i++) {
        ret += (n-i+1)*(f[i]*f[n-i+1]%m)%m;
    }
    printf("%lld", ret%m);
    return 0;
}
