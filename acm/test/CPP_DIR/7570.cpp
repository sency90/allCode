#include <stdio.h>
int idx[1000001], a[1000002];
int main() {
    int n, cnt=1, mx=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        idx[a[i]] = i;
    }
    for(int i=1; i<=n; i++) {
        int tmp = idx[a[i]];
        for(int j=a[i]+1; tmp < idx[j]; j++) {
            tmp = idx[j];
            cnt++;
        }
        if(mx < cnt) mx = cnt;
        cnt = 1;
    }
    printf("%d", n-mx);
    return 0;
}
