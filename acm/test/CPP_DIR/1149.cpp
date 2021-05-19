#include <stdio.h>
#define R 0
#define G 1
#define B 2

int color[1000][3];

int minCost(int curIdx, int curColor) {
    --curIdx;
    if(curIdx < 0) return -1; //error
    if(curColor == R) return color[curIdx][G] < color[curIdx][B] ? color[curIdx][G] : color[curIdx][B];
    else if(curColor == G) return color[curIdx][R] < color[curIdx][B] ? color[curIdx][R] : color[curIdx][B];
    else if(curColor == B) return color[curIdx][R] < color[curIdx][G] ? color[curIdx][R] : color[curIdx][G];
    else return -1; //error
}

int main() {
    int n; scanf("%d", &n);
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &color[i][j]);

            if(i > 0) {
                color[i][j] += minCost(i,j);
            }
        }
    }

    int min = color[n-1][R];
    for(i=1; i<3; i++) {
        if(min > color[n-1][i]) {
            min = color[n-1][i];
        }
    }

    printf("%d\n", min);
    return 0;
}
