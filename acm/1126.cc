#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[51], d[500001][51];
const int inf = 0x3f3f3f3f;
const int inf2 = inf+1;
int ABS(int x) { return x<0?-x:x; }
int f(int dif, int i) {
    if(dif>500000) return -inf;
    if(i==0) {
        if(dif==0) return 0;
        else return -inf;
    }
    if(d[dif][i]!=-inf2) return d[dif][i];
    return d[dif][i] = max({f(dif,i-1), f(dif+v[i],i-1)+v[i], f(ABS(dif-v[i]),i-1)+v[i]});
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &v[i]);

    memset(d, 0xc0, sizeof(d));
    int ans = f(0,n);
    if(ans<=0) puts("-1");
    else printf("%d", ans/2);
    return 0;
}
