#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int n, chk[26];
    char c;
    bool sp, dp, tp;
    scanf("%d ", &n);
    for(int k=1; k<=n; k++) {
        sp = dp = tp = true;
        memset(chk, 0, sizeof(chk));
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(isupper(c)) chk[c-'A']++;
            if(islower(c)) chk[c-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(chk[i] < 1) sp = false;
            if(chk[i] < 2) dp = false;
            if(chk[i] < 3) tp = false;
        }

        printf("Case %d: ", k);
        if(tp) puts("Triple pangram!!!");
        else if(dp) puts("Double pangram!!");
        else if(sp) puts("Pangram!");
        else puts("Not a pangram");
    }
    return 0;
}
