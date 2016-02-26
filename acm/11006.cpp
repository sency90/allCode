#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    int n, m;
    while(t--) {
        scanf("%d %d", &n, &m);
        printf("%d %d\n", m*2-n, n-m);
    }
    return 0;
}
