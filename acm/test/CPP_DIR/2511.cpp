#include <stdio.h>
int main() {
    int a[10], b[10], ascore=0, bscore=0;
    int lastWin = 0;
    for(int i=0; i<10; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<10; i++) {
        scanf("%d", &b[i]);
    }
    for(int i=0; i<10; i++) {
        if(a[i] > b[i]) {
            ascore += 3;
            lastWin = 1;
        } else if(a[i] < b[i]) {
            bscore += 3;
            lastWin = 2;
        } else {
            ascore++;
            bscore++;
        }

        if(i == 9) {
            printf("%d %d\n", ascore, bscore);
            if(ascore < bscore) puts("B");
            else if(ascore > bscore) puts("A");
            else {
                if(lastWin == 1) puts("A");
                else if(lastWin == 2) puts("B");
                else puts("D");
            }
        }
    }
    return 0;
}
