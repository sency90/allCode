#include <stdio.h>
#include <cstring>
using namespace std;
bool chk[10];
int cnt, ans;
void check(int n) {
    ans = n;
    while(n!=0) {
        if(!chk[n%10]) cnt++;
        chk[n%10] = true;
        n/=10;
    }
}
int main() {
    int t, n;
    scanf("%d", &t);
    for(int k=1; k<=t; k++) {
        memset(chk, false, sizeof(chk));
        cnt=0;
        scanf("%d", &n);
        if(n==0) {
            printf("Case #%d: INSOMNIA\n", k);
            continue;
        }
        for(int i=1; cnt!=10; i++) {
            check(n*i);
        }
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
