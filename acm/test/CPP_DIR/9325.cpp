#include <stdio.h>
int main() {
    int t, n, s, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &s, &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            s += x*y;
        }
        printf("%d\n", s);
    }
    return 0;
}
