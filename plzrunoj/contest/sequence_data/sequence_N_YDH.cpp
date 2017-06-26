#include <iostream>
using namespace std;
typedef long long ll;
ll a[300001], d, b;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0,t=1,mul=1; i<n; i++,t*=-1,mul++) {
        scanf("%lld", &a[i]);
        d+=t*a[i];
        b+=t*mul*a[i];
    }
    printf("%lld ", b);
    ll t = (n&1)?1LL:-1LL;
    for(int i=0; i<n-1; i++) {
        if(i==0) b = -b+d+t*n*a[i];
        else b = -b+d+t*n*a[i];
        d=-1LL*(d-a[i])+t*a[i];
        printf("%lld ", b);
    }
    return 0;
}
