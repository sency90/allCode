#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7LL;
map<int, map<int, ll>> d;
ll f(int n,int k) {
    if(n==k||k==0) return 1ll;
    ll &ret = d[n][k];
    if(ret) return ret;
    return ret = (f(n-1,k-1)+f(n-1,k))%mod;
}

int main() {
    int n,k;
    scanf("%d%d", &n,&k);
    printf("%lld", f(n+k,k-1));
    return 0;
}
