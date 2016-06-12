#include <stdio.h>
double a[200][200];
int main() {
    int n, t, ans=0;
    scanf("%d%d",&n,&t);
    for(int i=1; i<=t; i++) {
        a[1][1] += 1;
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=j; k++) {
                double ohead = a[j][k] - 1.0;
                printf("a[%d][%d]:%.11lf ,, ohead: %.11lf\n", j,k,a[j][k],ohead);
                if(ohead < 0) continue;
                a[j][k] = 1;
                a[j+1][k] += ohead/2;
                a[j+1][k+1] += ohead/2;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(a[i][j] > 1.0 - 1e-12) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
