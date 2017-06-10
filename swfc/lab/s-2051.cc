#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int coin[11], d[70001];
bool coinchk[70001];
bool chk[70001];
const int inf = 0x3f3f3f3f;
int n;
int f(int x) {
    if(coinchk[x]) return d[x]=1;
    if(chk[x]) return d[x];
    chk[x]=true;
    for(int i=0; i<n; i++) {
        if(x>=coin[i]) d[x] = min(d[x], f(x-coin[i])+1);
    }
    return d[x];
}
int main() {
    memset(d, 0x3f, sizeof(d));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &coin[i]);
        coinchk[coin[i]]=true;
    }
    sort(coin, coin+n);
    int w; scanf("%d", &w);
    int ans = f(w);
    if(ans>=inf) puts("impossible");
    else printf("%d", ans);
    return 0;
}
