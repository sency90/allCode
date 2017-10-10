#include <stdio.h>
int x[2001], y[2001];
bool chk[4000001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x[i]);
        chk[x[i]]=true;
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &y[i]);
        chk[y[i]]=true;
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(chk[x[i] ^ y[j]]) {
                cnt++;
            }
        }
    }
    if(cnt%2==0) puts("Karen");
    else puts("Koyomi");
    return 0;
}
