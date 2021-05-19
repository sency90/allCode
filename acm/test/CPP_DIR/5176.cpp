#include <stdio.h>
#include <string.h>
int main() {
    int t, p, m, d, sum, cnt[501];
    scanf("%d", &t);
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        sum = 0;
        scanf("%d %d", &p, &m);
        for(int i=0; i<p; i++) {
            scanf("%d", &d);
            cnt[d]++;
        }
        for(int i=1; i<=m; i++) {
            if(cnt[i] > 1) sum += cnt[i]-1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
