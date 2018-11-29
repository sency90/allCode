#include <stdio.h>
bool chk[4000];
int main() {
    //freopen("input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,p; scanf("%d %d", &n,&p);
        for(int i=0; i<n; i++) chk[i] = false;
        for(int i=0; i<p; i++) {
            int x; scanf("%d", &x);
            if(chk[x-1]) continue;
            for(int j=x-1; j<n; j+=x) chk[j] = true;
        }
        int cnt=0;
        for(int i=0; i<n; i++) if(chk[i] && i%7!=5 && i%7!=6) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
