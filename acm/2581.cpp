#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
    bool chk[10001], isFirst=true;
    memset(chk, false, sizeof(chk));
    int n, m, mn=-1, sum=0;
    scanf("%d %d", &n, &m);
    chk[1] = true;
    for(int i=2; i*i<=m; i++) {
        for(int j=i*i; j<=m; j+=i) {
            chk[j] = true;
        }
    }

    for(int i=n; i<=m; i++) {
        if(!chk[i]) {
            if(isFirst) {
                mn = i;
                isFirst = false;
            }
            sum+=i;
        }
    }

    if(mn==-1) puts("-1");
    else printf("%d\n%d",sum, mn);
    return 0;
}
