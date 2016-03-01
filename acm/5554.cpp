#include <stdio.h>
int main() {
    int sum=0, d;
    for(int i=0; i<4; i++) {
        scanf("%d", &d);
        sum += d;
    }
    printf("%d\n%d\n", sum/60, sum%60);
    return 0;
}
