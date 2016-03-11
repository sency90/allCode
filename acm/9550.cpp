#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    int n, k, d, sum;
    while(t--) {
        sum = 0;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            sum += d/k;
        }
        printf("%d\n", sum);
    }
    return 0;
}
