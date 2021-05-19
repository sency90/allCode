#include <stdio.h>
#include <string.h>
int chk(char c, char pc, char ppc) {
    //HHH, HHT, HTH, HTT, THH, THT, TTH, TTT
    if(c == 'H') {
        if(pc == 'H') {
            if(ppc == 'H') {
                return 7;
            } else if(ppc == 'T') {
                return 3;
            }
        } else if(pc == 'T') {
            if(ppc == 'H') {
                return 5;
            } else if(ppc == 'T') {
                return 1;
            }
        }
    } else if(c == 'T') {
        if(pc == 'H') {
            if(ppc == 'H') {
                return 6;
            } else if(ppc == 'T') {
                return 2;
            }
        } else if(pc == 'T') {
            if(ppc == 'H') {
                return 4;
            } else if(ppc == 'T') {
                return 0;
            }
        }
    }
    return -1;
}
int main() {
    char c, pc, ppc;
    int tmp, cnt[8];
    int t; scanf("%d ", &t);
    while(t--) {
        pc = 0; ppc = 0;
        memset(cnt, 0, sizeof(cnt));
        while((c = getchar())!='\n' && c!='\r' && c!=EOF) {
            if((tmp = chk(c, pc, ppc)) >= 0) {
                cnt[tmp]++;
            }
            ppc = pc;
            pc = c;
        }
        for(int i=0; i<8; i++) {
            printf("%d ", cnt[i]);
        }
        puts("");
    }
    return 0;
}
