#include <stdio.h>
#include <string.h>
int d[15][15];
int f(int lev, int b) {
    if(d[lev][b]) return d[lev][b];

    int ret=0;
    for(int i=1; i<=b; i++) {
        ret += f(lev-1, i);
    }
    return d[lev][b] = ret;
}
int main() {
    memset(d, 0, sizeof(d));
    int t, k, n;
    scanf("%d", &t);
    for(int i=1; i<15; i++) {
        d[0][i] = i;
    }
    while(t--) {
        scanf("%d %d", &k, &n);
        printf("%d\n", f(k, n));
    }
    return 0;
}
