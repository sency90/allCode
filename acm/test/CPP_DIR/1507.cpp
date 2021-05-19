#include <stdio.h>
int v[21][21];
bool chk[21][21];
int main() {
    int n, ans=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            chk[i][j] = false;
            scanf("%d", &v[i][j]);
            if(i<j) ans += v[i][j];
        }
    }
    bool wAns = false;
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n-1; i++) {
            for(int j=i+1; j<=n; j++) {
                if(i==k || j==k) continue;
                if(v[i][j] > v[i][k] + v[k][j]) {
                    wAns = true;
                    break;
                } else if((v[i][j] == v[i][k] + v[k][j]) && !chk[i][j]) {
                    chk[i][j] = true;
                    ans -= v[i][j];
                }
            }
            if(wAns) break;
        }
        if(wAns) break;
    }
    if(wAns) puts("-1");
    else printf("%d", ans);
}
