#include <stdio.h>
int main() {
    int t, cnt[5];
    double sum, cost[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        for(int i=0; i<5; i++) {
            scanf("%d", &cnt[i]);
            sum += cnt[i] * cost[i];
        }
        printf("$%.2lf\n", sum);
    }
    return 0;
}
