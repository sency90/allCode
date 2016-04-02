#include <stdio.h>
int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(b<0) {
        a=-((a+b+1)%n-1);
    } else {
        a=(a+b-1)%n+1;
    }
    printf("%d", a);
    return 0;
}
