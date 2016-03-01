#include <stdio.h>
#include <string.h>
int cnt[1001];
int main() {
    int n, m, x, y;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        cnt[x]++;
        cnt[y]++;
    }
    for(int i=1; i<=n; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
