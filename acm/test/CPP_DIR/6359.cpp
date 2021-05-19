#include <stdio.h>
#include <string.h>
bool room[101];
int main() {
    int t,n,cnt;
    scanf("%d",&t);
    while(t--) {
        for(int i=0; i<=100; i++) room[i] = true;
        cnt = 0;
        scanf("%d", &n);
        for(int i=2; i<=n; i++) {
            for(int j=i; j<=n; j+=i) {
                if(room[j]) room[j] = false;
                else room[j] = true;
            }
        }
        for(int i=1; i<=n; i++) {
            if(room[i]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
