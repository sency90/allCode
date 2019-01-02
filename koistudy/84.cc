#include <stdio.h>
typedef long long ll;
int main() {
    ll a,b,c,d;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    ll res = a*(b/8)*c*d;
    printf("%.1lf MB", double(res)/(1<<20));

}
