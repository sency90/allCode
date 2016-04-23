#include <stdio.h>
long long c;
long long f(long long x, long long n) {
    if(n==0) return 1LL;
    if(n%2==0) {
        long long half = f(x, n/2);
        return half*half%c;
    } else {
        return x*f(x, n-1)%c;
    }
}
int main() {
    long long a, b;;
    scanf("%lld%lld%lld", &a,&b,&c);
    printf("%lld", f(a,b));
    return 0;
}
