#include <iostream>
using namespace std;
typedef long long ll;
ll a[300001], d, b;
ll ABS(ll x) { return (x<0LL) ? -x : x; }
int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        if(i!=0) d+=((i&1) ? -1 : 1)*a[i];
        b += ((i&1) ? -1 : 1)*(i+1)*a[i];
    }
    ll ans=ABS(b);
    for (int i=0; i<n-1; i++) {
        b= -b+a[0]+((i&1) ? -1 : 1)*d+n*a[i];
        ans^=ABS(b);
    }
    printf("%lld\n", ans);
    return 0;
}
