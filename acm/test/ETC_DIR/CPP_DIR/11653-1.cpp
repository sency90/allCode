#include <stdio.h>
int main() {
    long long n;
    scanf("%lld", &n);
    for(long long i=2; i*i<=n; i++) {
        while(n%i == 0) {
            printf("%lld\n", i);
            n/=i;
        }
    }
    if(n!=1) printf("%lld\n", n);
    return 0;
}
