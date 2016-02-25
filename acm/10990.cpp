#include <stdio.h>
int main() {
    int n, len, i, j; scanf("%d", &n);
    for(i=0; i<n; i++) {
        len = n-i-1;
        for(j=0; j<len; j++) printf(" ");
        for(j=0; j<=i; j++) {
            if(i==j) printf("*");
            else if(j==0) printf("* ");
            else printf("  ");
        } printf("\n");
    } return 0;
}
