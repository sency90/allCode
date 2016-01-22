#include <stdio.h>
#include <string.h>

int main() {
    int d[31];
    int n;

    memset(d, 0, sizeof(d));

    d[0] = 1;
    d[2] = 3;

    scanf("%d", &n);

    for(int i=4; i<=n; i+=2) {
        d[i] = 3 * d[i-2];
        for(int j=4; j<=i; j+=2) {
            d[i] += (2 * d[i-j]);
        }
    }
    printf("%d\n", d[n]);

    return 0;
}
