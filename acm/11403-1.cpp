#include <stdio.h>
#define INF 1000
short v[100][100];
int main() {
    int n, i, j, k; scanf("%d",&n);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%hd", &v[i][j]);
            if(!v[i][j]) v[i][j] = INF;
        }
    }
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(v[i][j] > v[i][k]+v[k][j]) {
                    v[i][j] = v[i][k]+v[k][j];
                }
            }
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(v[i][j] == INF) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;
}
