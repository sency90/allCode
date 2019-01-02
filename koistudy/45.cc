#include <stdio.h>
typedef long long ll;
int main() {
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld\n", a+b+c);
    printf("%.1lf\n", (double(a)+b+c)/3.0);
    return 0;
}
