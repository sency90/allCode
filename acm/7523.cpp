#include <stdio.h>
int main() {
    long long t, n, m; scanf("%lld", &t);
    for(int i=1; i<=t; i++) {
        scanf("%lld %lld", &n, &m);
        printf("Scenario #%d:\n", i);
        if(m<=0 || n>=0) {
            printf("%lld\n\n", (n+m)*(m-n+1)/2);
        } else {
            printf("%lld\n\n", (n*(-n+1)/2) + (m*(m+1)/2));
        }
    }
    return 0;
}
