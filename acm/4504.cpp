#include <stdio.h>
int main() {
    int n, d; scanf("%d", &n);
    while(true) {
        scanf("%d", &d);
        if( d == 0 ) break;
        if(d%n == 0) printf("%d is a multiple of %d.\n", d, n);
        else printf("%d is NOT a multiple of %d.\n", d, n);
    }
    return 0;
}
