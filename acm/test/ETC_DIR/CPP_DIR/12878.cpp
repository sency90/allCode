#include <stdio.h>
int main() {
    long long a=1LL, b=2LL, t;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        t = 2*a;
        a = 2*b;
        b = t;
    }
    printf("%lld", b);
    return 0;
}
