#include <stdio.h>
bool chk[1000001];
int main() {
    int n,x;
    scanf("%d%d", &n, &x);
    for(int i=n; i>=1; i--) {
        if(x >= i) {
            chk[i] = true;
            x -= i;
        }
    }
    if(x>0) {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) printf("%d ", i);
    }
    puts("");
    return 0;
}
