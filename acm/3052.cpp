#include <stdio.h>
#include <string.h>
bool chk[1001];
int main() {
    int cnt=0, d;
    memset(chk, false, sizeof(chk));
    for(int i=0; i<10; i++) {
        scanf("%d", &d);
        d%=42;
        cnt++;
        if(chk[d]) cnt--;
        chk[d] = true;
    }
    printf("%d", cnt);
    return 0;
}
