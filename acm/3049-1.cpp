#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n*(n-1)/2*(n-2)/3*(n-3)/4);
    return 0;
}
