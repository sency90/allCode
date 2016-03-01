#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a, b, sum=0;
    while(n--) {
        scanf("%d %d", &a, &b);
        sum += b%a;
    }
    printf("%d", sum);
    return 0;
}
