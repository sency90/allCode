#include <stdio.h>
typedef long long ll;
int main() {
    ll a,m,d,n;
    scanf("%lld%lld%lld%lld",&a,&m,&d,&n);
    ll res = a;
    for(int i=1; i<n; i++) {
        res = res*m + d;
    }
    printf("%lld", res);
    return 0;
}
