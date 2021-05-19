#include <stdio.h>

int main() {
    char paren[50];
    int t, i, cnt;
    bool isBreak;

    scanf("%d", &t);
    while(t--) {
        cnt = 0;
        isBreak = false;
        scanf("%s", paren);
        for(i=0; paren[i]; i++) {
            if( '(' == paren[i]) cnt++;
            else if( ')' == paren[i] ) cnt--;
            else {
                printf("NO\n");
                isBreak = true;
                break;
            }

            if(cnt < 0) {
                printf("NO\n");
                isBreak = true;
                break;
            }
        }
        if(isBreak) continue;
        if(0 == cnt) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
