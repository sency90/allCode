#include <stdio.h>

int main() {
    int n, x, i, j; scanf("%d", &n);
    for(i=0; i<n; i++) {
        for(j=n-1; j>i; j--) printf(" ");
        x = 2*i+1;
        for(j=0; j<x; j++) printf("*");
        printf("\n");
    }
    for(i=1; i<=n; i++) {
        for(j=0; j<i; j++) printf(" ");
        for(j=2*(n-i)-1; j>0; j--) printf("*");
        printf("\n");
    }
    return 0;
}
