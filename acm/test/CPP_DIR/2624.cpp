#include <stdio.h>
#include <string.h>
int coin[100], cnt[100];
int d[10001][100];
int f(int m, int idx) {
    if(idx == -1) {
        if(m == 0) return 1;
        else return 0;
    }
    if(d[m][idx] != -1) return d[m][idx];

    int ret = 0;
    for(int i=0; i<=cnt[idx]; i++) {
        if(m < coin[idx]*i) break;
        ret += f(m-coin[idx]*i, idx-1);
    }
    return d[m][idx] = ret;
}
int main() {
    memset(d, -1, sizeof(d));
    int m, cc;
    scanf("%d %d", &m, &cc);
    for(int i=0; i<cc; i++) {
        scanf("%d %d", &coin[i], &cnt[i]);
    }
    printf("%d", f(m, cc-1));
    return 0;
}
