#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int d[301][2], v[301];
int f(int x, int y) {
    if(x==0) return 0;
    if(x==1) return v[1];
    if(d[x][y]>0) return d[x][y];
    if(y==0) d[x][y] = max(f(x-2,0),f(x-2,1))+v[x];
    else d[x][y] = f(x-1,0)+v[x];
    return d[x][y];
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d", max(f(n,0),f(n,1)));
    return 0;
}
