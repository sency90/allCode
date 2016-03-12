#include <stdio.h>
#include <string.h>
#include <ctype.h>
int chg(char *s) {
    int len = strlen(s), res = 0;
    for(int i=0; i<len; i++) {
        if(isupper(s[i])) res += s[i]-'A'+27;
        else res += s[i]-'a'+1;
    }
    return res;
}
int main() {
    char s[21]; scanf("%s", s);
    int d = chg(s), i, j;
    bool chk[d+1];
    memset(chk, false, sizeof(chk));
    for(i=2; i<=d; i++) {
        for(j=i*i; j<=d; j+=i) {
            chk[j] = true;
        }
    }
    if(!chk[d]) puts("It is a prime word.");
    else puts("It is not a prime word.");
}
