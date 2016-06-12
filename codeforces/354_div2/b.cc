#include <stdio.h>
double a[11][11];
int main() {
    int n, t;
    scanf("%d%d",&n,&t);
    for(int z=1; z<=t; z++) {
        a[1][1]++;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                double ohead = a[i][j] - 1.0;
                if(ohead < 0) continue;
                a[i][j]=1;
                a[i+1][j] += ohead/2;
                a[i+1][j+1] += ohead/2;
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(a[i][j]>1.0-1e-12) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
