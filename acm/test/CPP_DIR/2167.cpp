#include <stdio.h>

int main() {
    int sum, n, m, k, i, j, x, y, arr[300][300];
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        sum = 0;
        for(int p=j-1; p<y; p++) {
            for(int q=i-1; q<x; q++) {
                sum += arr[p][q];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
