#include <stdio.h>
#include <algorithm>
using namespace std;
char s[300][301];
int main() {
    int n, m, xe, ye, i, j, x, y, d;
    bool isBrk;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%s", s[i]);
    for(d=min(n,m); d>1; d--) {
        for(i=0; i<=n-d; i++) {
            for(j=0; j<=m-d; j++) {
                xe = i+d-1;
                isBrk = false;
                for(x=i; x<i+d; x++) {
                    ye = j+d-1;
                    for(y=j; y<j+d; y++) {
                        if(s[x][y]!=s[xe][ye]) {
                            isBrk = true;
                            break;
                        }
                        ye--;
                    }
                    if(isBrk) break;
                    xe--;
                }
                if(!isBrk) {
                    printf("%d", d);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}
