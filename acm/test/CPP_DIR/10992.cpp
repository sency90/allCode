#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=n-i; j>=1; j--) printf(" ");
        if(i==n) {
            for(int j=1; j<=i; j++) {
                if(j==i) printf("*");
                else printf("**");
            }
        } else {
            for(int j=1; j<=i; j++) {
                if(j==i || j==1) printf("*");
                else printf("  ");
                if(j==1) printf(" ");
            } printf("\n");
        }
    } return 0;
}
