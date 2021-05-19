#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, a, b, d[101];
int p=0x3f3f3f3f, q=0x3f3f3f3f;
bool chk[101];
int f(int x) {
    if(x<=0) return 0;
    if(chk[x]) return d[x];
    chk[x] = true;
    return d[x] = min(f(x-6)+p,f(x-1)+q);
}
int main() {
    int n, m, a, b;
    memset(chk, false, sizeof(chk));
    scanf("%d %d",&n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        if(p > a) p = a;
        if(q > b) q = b;
    }
    printf("%d\n", f(n));
    return 0;
}
