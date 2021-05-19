#include <stdio.h>
long long d[91][2];
int n;
long long f(int x, int y) {
    if(x==n) return y;
    if(d[x][y]>0) return d[x][y];
    if(y==0) d[x][y]=f(x+1,y^1)+f(x+1,y);
    else d[x][y]=f(x+1,y^1);
    return d[x][y];
}
int main() {
    scanf("%d", &n);
    printf("%lld", f(1,1)+f(1,0));
    return 0;
}
