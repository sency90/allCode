#include <stdio.h>
int main() {
    long long l, u; scanf("%lld %lld", &l, &u);
    printf("%lld\n", (u-l+1)*(l+u)/2);
    return 0;
}
