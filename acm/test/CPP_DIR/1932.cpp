#include <stdio.h>

int main() {
    short i, j, n;
    int res = 0, v[500][500];

    scanf("%hd", &n);
    if(n == 1) {
        scanf("%d", &res);
    } else {
        for(i=0; i<n; i++) {
            for(j=0; j<i+1; j++) {
                scanf("%d", &v[i][j]);
                if(i > 0) {
                    if(j == 0) v[i][j] += v[i-1][j];
                    else if(i == j) v[i][j] += v[i-1][j-1];
                    else v[i][j] += (v[i-1][j-1] > v[i-1][j]? v[i-1][j-1]:v[i-1][j]);
                }
            }
        }
        for(i=0; i<n; i++) {
            if(res < v[n-1][i]) res = v[n-1][i];
        }
    }
    printf("%d\n", res);
    return 0;
}