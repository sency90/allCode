#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    int n, d, v, f, c, cnt;
    while(t--) {
        scanf("%d %d", &n, &d);
        cnt=0;
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &v, &f, &c);
            if(d*c <= f*v) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
