#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main() {
    freopen("input.txt","w",stdout);
    int n=100000; printf("%d\n",n);
    const ll lim = 1e18;
    for(int i=0; i<n; i++) {
        ll x=(ll(rand())<<32) | ll(rand());
        x%=lim;
        if(x==0LL) x++;
        printf("%lld\n",x);
    }
}
