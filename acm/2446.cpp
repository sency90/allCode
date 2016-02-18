#include <stdio.h>
int main() {
    int n, lim; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) printf(" ");
        lim = 2*n - 2*i;
        for(int j=0; j<=lim; j++) printf("*");
        printf("\n");
    }
    for(int i=n-1; i>=1; i--) {
        for(int j=1; j<i; j++) printf(" ");
        lim = 2*n - 2*i;
        for(int j=0; j<=lim; j++) printf("*");
        printf("\n");
    }
    return 0;
}
