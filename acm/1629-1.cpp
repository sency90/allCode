#include <stdio.h>
long long a, c;
long long spow(long long b) {
    if(b==0) return 1LL;
    long long ret = spow(b/2);
    ret = ret*ret%c;
    if(b%2) ret = ret*a%c;
    return ret;
}
int main() {
    long long b;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld", spow(b));
    return 0;
}
