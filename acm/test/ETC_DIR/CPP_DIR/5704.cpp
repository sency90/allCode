#include <stdio.h>
#include <string.h>
int main() {
    bool chk[26];
    int i;
    char c;
    while(true) {
        memset(chk, false, sizeof(chk));
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(c==' ') continue;
            else if(c=='*') return 0;
            chk[c-'a'] = true;
        }
        for(i=0; i<26; i++) if(!chk[i]) break;
        if(i==26) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
