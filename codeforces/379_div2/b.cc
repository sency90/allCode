#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a,b,c,d;
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int mn = min({a,c,d});
    a-=mn;
    ll ans = (ll)mn*256LL+(ll)min(a,b)*32LL;
    printf("%lld", ans);
    return 0;
}
