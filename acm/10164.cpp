#include <stdio.h>
int d[16][16];
int f(int x, int y) {
    if(x<1 || y<1) return 0;
    if(x==1 || y==1) return 1;
    if(d[x][y] > 0) return d[x][y];
    return d[x][y] = f(x-1, y) + f(x, y-1);
}
int main() {
    int n, m, k, x, y;
    scanf("%d %d %d", &n, &m, &k);
    bool exist;
    if(k==0) exist = false;
    else exist = true;
    x = (k-1)/m+1;
    y = (k-1)%m+1;
    if(exist) {
        printf("%d", f(x, y)*f(n-x+1, m-y+1));
    } else {
        printf("%d", f(n, m));
    }
    return 0;
}
