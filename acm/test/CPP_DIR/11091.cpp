#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    bool chk[26];
    int i, j, t;
    char c;
    scanf("%d ", &t);
    while(t--) {
        memset(chk, false, sizeof(chk));
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(isupper(c)) chk[c-'A'] = true;
            if(islower(c)) chk[c-'a'] = true;
        }
        for(i=0; i<26; i++) if(!chk[i]) break;
        if(i==26) printf("pangram");
        else {
            printf("missing ");
            for(j=i; j<26; j++) if(!chk[j]) printf("%c", j+'a');
        }
        printf("\n");
    }
    return 0;
}
