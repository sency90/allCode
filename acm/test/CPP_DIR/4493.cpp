#include <stdio.h>
int main() {
    int t, ca, cb, n;
    char a, b;
    scanf("%d", &t);
    while(t--) {
        ca=0; cb=0;
        scanf("%d", &n);
        while(n--) {
            scanf(" %c %c", &a, &b);
            if(a=='P' && b=='S') cb++;
            else if(a=='S' && b=='P') ca++;
            else if(a<b) ca++;
            else if(a>b) cb++;
        }
        if(ca == cb) printf("TIE\n");
        else if(ca > cb) printf("Player 1\n");
        else printf("Player 2\n");
    }
    return 0;
}
