#include <stdio.h>
int main() {
    unsigned char n, i, j; scanf("%hhu", &n);
    unsigned char lim, t = n;
    for(i=0; i<n; i++) {
        for(j=0; j<i; j++) printf(" ");
        lim = 2*(n-i)-1;
        for(j=0; j<lim; j++) printf("*");
        printf("\n");
    }
    return 0;
}
