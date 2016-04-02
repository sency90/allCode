#include <stdio.h>
#include <string.h>
#define RND 1000000000
int d[1000001];
int main() {
    int n; scanf("%d", &n);
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for(int i=0; (1<<i)<=n; i++) {
        for(int j=(1<<i); j<=n; j++) {
            d[j] = (d[j]+d[j-(1<<i)])%RND;
        }
    }
    printf("%d", d[n]);
    return 0;
}
