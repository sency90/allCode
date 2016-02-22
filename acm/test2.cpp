#include <stdio.h>
int main() {
    int p, x, q, r;
    do {
        scanf("%d", &p);
        x = -2;
        printf("p/x: %d,  p(mod)x: %d\n", p/x, p%x);
    } while(p!=EOF);
    return 0;
}
