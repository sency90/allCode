#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    int coin[100];
    int d[10001];
    memset(coin, 0, sizeof(coin));
    memset(d, 0, sizeof(d));

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &coin[i]);
    }

    for(int i=0; i<k+1; i+=coin[0]) {
        ++d[i];
    }

    for(int i=1; i<n; i++) {
        for(int j=coin[i]; j<k+1; j++) {
            d[j] += d[j-coin[i]];
        }
    }

    printf("%d\n", d[k]);
    return 0;
}
