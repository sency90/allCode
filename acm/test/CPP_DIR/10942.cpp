#include <stdio.h>
int d[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d[i]);
    }
    int m, s, e, r; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &s, &e);
        r = 1;
        while(s < e) {
            if(d[s++]!=d[e--]) r = 0;
        }
        printf("%d\n", r);
    }
}
