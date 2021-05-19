#include <stdio.h>
int main() {
    int i, j, n, d[1001], a[1001], max, rMax;
    rMax = 1;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        d[i] = 1;
        max = 0;
        for(j=0; j<i; j++) {
            if(a[j] < a[i]) {
                if(max < d[j]) max = d[j];
            }
        }
        d[i] = max+1;
        if(rMax < d[i]) rMax = d[i];
    }
    printf("%d", rMax);
    return 0;
}
