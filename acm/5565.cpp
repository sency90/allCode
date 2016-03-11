#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int d, sum=0;
    for(int i=0; i<9; i++) {
        scanf("%d", &d);
        sum += d;
    }
    printf("%d", n-sum);
    return 0;
}
