#include <stdio.h>
int main() {
    int x, l, p; scanf("%d %d", &l, &p);
    l *= p;
    for(int i=0; i<5; i++) {
        scanf("%d", &x);
        printf("%d ", x-l);
    } return 0;
}
