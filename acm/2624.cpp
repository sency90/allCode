#include <stdio.h>
#include <string.h>
int coin[101], cnt[101], d[10001], t, k;
bool isIn[10001];
int f(int x) {
    int i=1;
    for(; i<=k; i++) {
        if(x == coin[i]) return d[x]+=1;
    }
    if(isIn[x]) return d[x];

    int j;
    for(i=1; i<=k; i++) {
        for(j=2; j<=cnt[i]; j++) {
            if(x < coin[i]*j) break;
            d[x] += f(x-coin[i]*j);
        }
    }
    isIn[x] = true;
    return d[x];
}
int main() {
    memset(isIn, false, sizeof(isIn));
    memset(d, 0, sizeof(d));
    int t, k; scanf("%d %d", &t, &k);
    for(int i=1; i<=k; i++) {
        scanf("%d %d", &coin[i], &cnt[i]);
    }
    printf("%d", f(t));
    return 0;
}
