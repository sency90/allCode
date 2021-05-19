#include <stdio.h>
int main() {
    long long n, sum=0LL, d, tmp;
    scanf("%lld", &n);
    for(long long i=1LL; i<=n; i++) {
        scanf("%lld", &d);
        tmp = d*i-sum;
        printf("%lld ", d*i-sum);
        sum+=tmp;
    }
    return 0;
}
