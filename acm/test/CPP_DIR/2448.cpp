#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ar[3072][6145];
void printvoid(int x, int y, int n) {
    int k = 2*n-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            ar[x+i][y+i+j] = ' ';
        }
        k-=2;
    }
}
void printstar(int x, int y, int n) {
    if(n==1) return;
    int m = n/2;
    printstar(x, y, m);
    printstar(x+m, y-m, m);
    printstar(x+m, y+m, m);
    printvoid(x+m, y-m+1, m);
}
int main() {
    int n, j; scanf("%d", &n);

    for(int i=0; i<n; i++) {
        j=0;
        for(; j<n-i-1; j++) {
            ar[i][j] = ' ';
        } for(; j<n+i; j++) {
            ar[i][j] = '*';
        }
        ar[i][j]=NULL;
    }

    printstar(0,n-1,n);
    for(int i=0; i<n; i++) {
        printf("%s", ar[i]);
        for(int j=0; j<n-i+1; j++) {
            putchar(' ');
        }puts("");
    }

    return 0;
}
