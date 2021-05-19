#include <stdio.h>
#include <cstring>
#define NINF -10000000
using namespace std;
int d[101][101];
int a[101],s[101];
bool chk[101][101];
int f(int x, int y) {
    if(y==0) return 0;
    else if(x<=0) return NINF;
    if(chk[x][y]) return d[x][y];
    chk[x][y] = true;
    int tmp, mx;
    mx = f(x-1, y);
    for(int i=1; i<=x; i++) {
        tmp = f(i-2, y-1) + s[x]-s[i-1];
        if(mx < tmp) mx = tmp;
    }
    return d[x][y] = mx;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    s[0]=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        s[i]=s[i-1]+a[i];
    }
    printf("%d", f(n, m));
    return 0;
}
