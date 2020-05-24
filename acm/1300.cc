#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> b;
int main() {
    ll n = 100000, lim = 50000LL * 50000LL;
    for(ll i=1; i<=n; i++) {
        for(ll j=i; j<=n; j++) {
            if(i*j >= lim) break;
            b.push_back(i*j);
            if(i!=j) b.push_back(i*j);
        }
    }
    sort(b.begin(), b.end());
    printf("%lu\n", b.size());
#if 0
    int n,k; scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            b.push_back(i*j);
        }
    }
    sort(b.begin(), b.end());
    for(int i=0; i<b.size(); i++) {
        printf("%lld ", b[i]);
    }
    puts("");
#endif
    return 0;
}
