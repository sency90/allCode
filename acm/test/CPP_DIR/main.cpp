#include <stdio.h>
#define SIZE 1001

short preN[SIZE], symN[SIZE];
short indPreN[SIZE], indSymN[SIZE];
short nodeNum;

void rf(int ls, int dVal, int re) {

    int le;
    if(indSymN[dVal]-1 < ls) {
        le = 0;
        ls = 0;
    } else {
        le = indSymN[dVal]-1;
    }

    int rs;
    if(indSymN[dVal]+1 > re) {
        re = 0;
        rs = 0;
    } else {
        rs = indSymN[dVal]+1;
    }

    int minPreInd;
    minPreInd = le;
    if(ls != 0) {
        if(ls >= le) {
            printf("%hd ", symN[ls]);
            ls = 0;
        } else {
            for(int i=ls; i<=le; i++) {
                if(minPreInd > indPreN[symN[i]]) {
                    minPreInd = indPreN[symN[i]];
                }
            }
            rf(ls, preN[minPreInd], le);
        }
    }

    if(re != 0) {
        minPreInd = re;
        if(rs >= re) {
            printf("%hd ", symN[rs]);
            re = 0;
        } else {
            for(int i=rs; i<=re; i++) {
                if(minPreInd > indPreN[symN[i]]) {
                    minPreInd = indPreN[symN[i]];
                }
            }
            rf(rs, preN[minPreInd], re);
        }
    }

    printf("%d ", dVal);
    return;
}

int main() {
    int testCase, i, j;
    scanf("%d", &testCase);
    for(i=0; i<testCase; i++) {
        scanf("%hd", &nodeNum);
        for(j=1; j<=nodeNum; j++) {
            scanf("%hd", &preN[j]);
            indPreN[preN[j]]=j;
        }
        for(j=1; j<=nodeNum; j++) {
            scanf("%hd", &symN[j]);
            indSymN[symN[j]]=j;
        }

        rf(1,preN[1],nodeNum);
        printf("\n");
    }
    return 0;
}
