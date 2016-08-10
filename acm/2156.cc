#include <cstdio>
#include <algorithm>
using namespace std;
int d[10002][2], v[10002], n;
int f(int x, int s) {
    if(x<=1) return x*v[s];
    if(d[x][s] > 0) return d[x][s];
    return d[x][s] = max(f(x-1,s^1),f(x-2,s^1)+(s^1)*v[x-1])+s*v[x];
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);
    printf("%d", max(f(n+1,0),f(n+1,1)));
    return 0;
}
