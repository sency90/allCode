#include <stdio.h>
int main() {
    int d, sum=0;
    for(int i=0; i<5; i++) {
        scanf("%d", &d);
        sum += d*d;
    }
    printf("%d", sum%10);
    return 0;
}
