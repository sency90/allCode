#include <stdio.h>
typedef long long ll;
int main() {
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%.2lf MB\n", double(a)*b*c/(1LL<<23));
    return 0;
}
