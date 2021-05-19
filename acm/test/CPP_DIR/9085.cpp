#include <stdio.h>
int main() {
    int t, n, d, sum;
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &d);
            sum += d;
        }
        printf("%d\n", sum);
    }
    return 0;
}
