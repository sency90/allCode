#include <stdio.h>
int main() {
    int sum=0, d;
    for(int i=0; i<5; i++) {
        scanf("%d", &d);
        sum += d;
    }
    printf("%d", sum);
    return 0;
}
