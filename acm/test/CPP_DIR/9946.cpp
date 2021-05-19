#include <stdio.h>
#include <string.h>
int main() {
    int chk[26], len1, len2;
    int i, j, k=0;
    char s1[1001], s2[1001];
    while(true) {
        ++k;
        scanf("%s", s1);
        scanf("%s", s2);
        if((!strcmp(s1, "END")) && (!strcmp(s2, "END"))) return 0;
        len1 = strlen(s1);
        len2 = strlen(s2);
        if(len1!=len2) {
            printf("Case %d: different\n", k);
            continue;
        }

        memset(chk, 0, sizeof(chk));
        for(i=0; i<len1; i++) {
            chk[s1[i]-'a']++;
            chk[s2[i]-'a']--;
        }

        for(j=0; j<26; j++) {
            if(chk[j] != 0) break;
        }
        if(j == 26) printf("Case %d: same\n", k);
        else printf("Case %d: different\n", k);
    }
    return 0;
}
