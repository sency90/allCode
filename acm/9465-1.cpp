#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int d[100001][2];
bool chk[100001][2];
int f(int n, int x) {
    if(n<1) return 0;
    if(chk[n][x]) return d[n][x];
    chk[n][x] = true;
    return d[n][x] = max(f(n-1, 1-x), max(f(n-2, 1-x), f(n-2, x))) + d[n][x];
}
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        memset(d, 0, sizeof(d));
        memset(chk, false, sizeof(chk));
        scanf("%d", &n);
        for(int j=0; j<2; j++) {
            for(int i=1; i<=n; i++) {
                scanf("%d", &d[i][j]);
            }
        }
        int t1 = f(n,0), t2 = f(n,1);
        if(t1>t2) printf("%d\n", t1);
        else printf("%d\n", t2);
    }
    return 0;
}
