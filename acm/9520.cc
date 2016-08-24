#include <cstdio>
#include <algorithm>
using namespace std;
int v[1501][1501], n, d[1501][1501];
int f(int x, int l, int r) {
    if(x==n) return 0;
    if(d[l][r]>0) return d[l][r];
    return d[l][r] = min(v[x][l]+f(x+1,x,r), v[r][x]+f(x+1,l,x));
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    printf("%d", f(0,0,0));
    return 0;
}
