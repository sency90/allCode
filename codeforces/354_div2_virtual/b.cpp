#include <stdio.h>
double v[11][11];
int main() {
    int n, t;
    scanf("%d%d",&n,&t);
    for(int z=1; z<=t; z++) {
        v[1][1]++;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                if(v[i][j]>=1.0) {
                    v[i+1][j] += (v[i][j]-1.0)/2;
                    v[i+1][j+1] += (v[i][j]-1.0)/2;
                    v[i][j]=1.0;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(v[i][j]>1.0-(1e-12)) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
