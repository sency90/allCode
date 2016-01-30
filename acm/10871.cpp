#include <stdio.h>
int main() {
    short n, x, a;
    scanf("%hd %hd", &n, &x);
    for(short i=0; i<n; i++) {
        scanf("%hd", &a);
        if(a < x) {
            printf("%hd ", a);
        }
    }
    printf("\n");
    return 0;
}
