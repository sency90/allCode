#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char d[100001], ans[100002];
int main() {
    int t, j, len, tmp;
    bool carry, isBrk;
    scanf("%d ", &t);
    while(t--) {
        scanf("%s", d);
        len = strlen(d)-1;
        carry = false, isBrk = false;
        for(j=0; j<=len; j++) {
            if(carry) ans[j] = 1;
            else ans[j] = 0;
            if((tmp = d[j]-'0'+d[len-j]-'0'+ans[j]) >= 10) carry = true;
            else carry = false;
            ans[j] = tmp%10;
        }
        if(carry) {
            ans[j] = 1;
            len = j;
        } else len = j-1;
        for(int k=0; k<=len; k++) {
            if(k>len-k) break;
            if(ans[k] != ans[len-k]) {
                isBrk = true;
                break;
            }
        }
        if(!isBrk) puts("YES");
        else puts("NO");
    }
    return 0;
}
