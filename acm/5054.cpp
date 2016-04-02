#include <stdio.h>
int main() {
    int t, n, mx, mn, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        mx = 0;
        mn = 100;
        while(n--) {
            scanf("%d", &d);
            if(mn > d) mn = d;
            if(mx < d) mx = d;
        }
        printf("%d\n", (mx-mn)*2);
    }
    return 0;
}
