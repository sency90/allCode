#include <stdio.h>
int a[10];
int main() {
    int n, k, cnt=0, i;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(i=n-1; i>=0; i--) {
        cnt += k/a[i];
        k %= a[i];
    }
    printf("%d", cnt);
    return 0;
}
