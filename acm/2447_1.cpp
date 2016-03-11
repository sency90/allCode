#include <stdio.h>
char ar[6561][6561];
void printvoid(int x, int y, int n) {
    if(n==1) {
        ar[x][y] = ' ';
        return;
    }
    int m = n/3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printvoid(x+m*i, y+m*j, m);
        }
    }
}
void printstar(int x, int y, int n) {
    if(n==1) {
        ar[x][y] = '*';
        return;
    }
    int m = n/3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1) printvoid(x+m*i, y+m*j, m);
            else printstar(x+m*i, y+m*j, m);
        }
    }
}
int main() {
    int n; scanf("%d", &n);
    printstar(0,0,n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%c", ar[i][j]);
        }
        puts("");
    }
    return 0;
}
