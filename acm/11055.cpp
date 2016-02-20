#include <stdio.h>
int main() {
    int i, j, n, d[1001], a[1001], max;
    max = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        d[i] = a[i];
        for(j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(d[i] < d[j] + a[i]) d[i] = d[j] + a[i];
            }
        }
        if(max < d[i]) max = d[i];
    }
    printf("%d", max);
    return 0;
}
