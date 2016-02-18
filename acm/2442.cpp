#include <stdio.h>
int main() {
    unsigned char n, i, j; scanf("%hhu", &n);
    unsigned char lim, t = n;
    for(i=0; i<n; i++) {
        lim = --t;
        for(j=0; j<lim; j++) printf(" ");
        lim = 2*i+1;
        for(j=0; j<2*i+1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
