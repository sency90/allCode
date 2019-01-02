#include <stdio.h>
int cnt[24];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for(int i=1; i<=23; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}
