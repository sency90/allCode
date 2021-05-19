#include <stdio.h>
char ar[64][64];
void solve(int x, int y, int n) {
    bool isBrk = false;
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(ar[x][y] != ar[i][j]) {
                isBrk = true;
                break;
            }
        }
        if(isBrk) break;
    }

    if(isBrk) {
        printf("(");
        int m=n/2;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                solve(x+i*m, y+j*m, m);
            }
        }
        printf(")");
    } else {
        printf("%d", ar[x][y]);
    }
}
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1hhd", &ar[i][j]);
        }
    }
    solve(0,0,n);
    return 0;
}
