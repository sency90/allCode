#include <stdio.h>
int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", (3*n*(n+1)/2+n+1)%45678);
    return 0;
}
