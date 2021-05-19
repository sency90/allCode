#include <stdio.h>
#include <string.h>
int v[100001][2];
int sum[100001][2];
int a, b;
int f( int x, int y ) {
    if(x==0) return 0;
    if(x==1) return v[x][y];
    if(sum[x][y] > 0) return sum[x][y];

    if(y == 1) sum[x][y] = ((a=f(x-1,0))>(b=f(x-2,0))?a:b) + v[x][y];
    else sum[x][y] = ((a=f(x-1,1))>(b=f(x-2,1))?a:b) + v[x][y];
    return sum[x][y];
}
int main() {
    int t; scanf("%d", &t);
    int n, a, b;
    while(t--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            sum[i][0] = 0;
            sum[i][1] = 0;
            scanf("%d", &v[i][0]);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i][1]);
        }
        a = f(n, 0);
        b = f(n, 1);
        printf("%d\n", a>b?a:b);
    }
    return 0;
}
