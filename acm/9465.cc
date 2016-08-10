#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int v[100001][2], d[100001][2];
int f(int x, int y) {
    if(x<=1) return v[x][y];
    if(d[x][y]>0) return d[x][y];
    return d[x][y] = max(f(x-1,y^1), f(x-2,y^1))+v[x][y];
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &v[i][0]);
        for(int i=1; i<=n; i++) scanf("%d", &v[i][1]);
        printf("%d\n", max(f(n,0),f(n,1)));
        memset(d, 0, sizeof(d));
    }
    return 0;
}
