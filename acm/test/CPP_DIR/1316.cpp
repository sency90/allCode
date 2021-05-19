#include <stdio.h>
#include <string.h>
int main() {
    bool isGword, dnchk[27];
    char c, prev;
    int n, cnt=0; scanf("%d ", &n);
    while(n--) {
        isGword = true;
        prev = 26;
        memset(dnchk, false, sizeof(dnchk));
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            c -= 'a';
            if(!isGword) {
                continue;
            }
            if(dnchk[c]) {
                isGword = false;
                continue;
            }
            if(prev != c) {
                dnchk[prev] = true;
            }
            prev = c;
        }
        if(isGword) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
