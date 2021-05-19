#include <cstdio>
using namespace std;
int v[129][129];
int a,b;
void f(int sx, int sy, int ex, int ey) {
    int mx=(sx+ex)/2, my=(sy+ey)/2;
    int area = (ex-sx+1)*(ey-sy+1);
    if(v[ex][ey]-v[sx-1][ey]-v[ex][sy-1]+v[sx-1][sy-1] == area) a++;
    else if(v[ex][ey]-v[sx-1][ey]-v[ex][sy-1]+v[sx-1][sy-1] == 0) b++;
    else {
        f(sx, sy, mx, my);
        f(sx, my+1, mx, ey);
        f(mx+1, sy, ex, my);
        f(mx+1, my+1, ex, ey);
    }
}
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &v[i][j]);
            v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }
    f(1,1,n,n);
    printf("%d\n%d\n",b,a);
    return 0;
}
