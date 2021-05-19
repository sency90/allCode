#include <stdio.h>
const int MOD = 1000000007;
int d[2001][2001];
int sum(int x, int y) {
    if(x+y>=MOD) return x+y-MOD;
    else return x+y;
}
int main() {
    int n,l,s=0;
    scanf("%d%d", &n,&l);
    for(int i=1; i<=n; i++) d[1][i]=1;
    for(int i=1; i<l; i++) {
        for(int last=1; last<=n; last++) {
            for(int j=last; j<=n; j+=last) {
                d[i+1][j] = sum(d[i+1][j],d[i][last]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        s = sum(s,d[l][i]);
    }
    printf("%d", s);
    return 0;
}
