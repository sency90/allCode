#include <stdio.h>
#include <cstring>
char ps[13], s[13];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s %s", ps, s);
    bool isAsc = false, isBrk = false;
    if(strcmp(ps, s)<0) {
        isAsc = true;
        strcpy(ps,s);
        for(int i=0; i<n-2; i++) {
            scanf("%s", s);
            if(strcmp(ps, s)>0) {
                puts("NEITHER");
                isBrk = true;
                break;
            }
            strcpy(ps,s);
        }
    } else {
        strcpy(ps,s);
        for(int i=0; i<n-2; i++) {
            scanf("%s", s);
            if(strcmp(ps, s)<0) {
                puts("NEITHER");
                isBrk = true;
                break;
            }
            strcpy(ps,s);
        }
    }
    if(isBrk) {
        while(scanf("%s", s)!=EOF);
        return 0;
    }
    if(isAsc) puts("INCREASING");
    else puts("DECREASING");
    return 0;
}
