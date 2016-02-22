#include <stdio.h>
int main() {
    int n, d, x[4]; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        x[0] = d/25;
        x[1] = (d%=25)/10;
        x[2] = (d%=10)/5;
        x[3] = d%5;
        for(int j=0; j<4; j++) {
            printf("%d ", x[j]);
        }
        printf("\n");
    }
    return 0;
}
