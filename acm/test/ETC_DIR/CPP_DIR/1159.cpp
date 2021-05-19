#include <stdio.h>
#include <string.h>
int main() {
    char s[31];
    int cnt[26];
    bool isgiveup = true;
    int t; scanf("%d", &t);
    memset(cnt, 0, sizeof(cnt));
    while(t--) {
        scanf("%s", s);
        cnt[s[0]-'a']++;
    }
    for(int i=0; i<26; i++) {
        if(cnt[i] >= 5) {
            printf("%c", i+'a');
            isgiveup = false;
        }
    }
    if(isgiveup) printf("PREDAJA\n");
    return 0;
}
