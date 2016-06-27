#include <stdio.h>
long long spow(long long x, int y) {
    long long res = 1;
    for(int i=0; i<y; i++) {
        res = res * x;
    }
    return res;
}
int main() {
    int n;
    long long d, sum = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        sum = (sum + spow(d/10, d%10));
    }
    printf("%lld", sum);
    return 0;
}
