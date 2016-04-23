#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int d[10001][2], v[10001];
int f(int x, int a) {
    if(x<0) return 0;
    if(d[x][a]!=-1) return d[x][a];
    if(a==0) d[x][a] = max(f(x-1, 1-a), f(x-1, a));
    else d[x][a] = max(f(x-1, 1-a), f(x-2, 1-a)+v[x-1])+v[x];
    return d[x][a];
}
int main() {
    memset(d, -1, sizeof(d));
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    int t1=f(n,0), t2=f(n,1);
    if(t1 > t2) printf("%d", t1);
    else printf("%d", t2);
    return 0;
}
