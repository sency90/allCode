#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;
int main() {
    int n; scanf("%d", &n);
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    ll lo=1, hi=1e9;
    while(lo<hi) {
        ll k=(lo+hi)/2;
        bool good = true;
        for(int i=1; i<=n; i++) {
            if(i*k>v[i]) {
                good=false;
                break;
            }
        }
        if(good) lo=k+1;
        else hi=k;
    }
    printf("%lld", lo-1);
    return 0;
}
