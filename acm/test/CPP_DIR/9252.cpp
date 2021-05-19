#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
char x[1001], y[1001], chk[1001][1001];
int d[1001][1001];
int f(int i, int j) {
    if(i<0 || j<0) return 0;
    if(d[i][j]>0) return d[i][j];
    if(x[i]==y[j]) {
        chk[i][j] = 0;
        return d[i][j] = f(i-1,j-1)+1;
    } else {
        int t1=f(i-1,j), t2=f(i,j-1);
        if(t1>t2) {
            chk[i][j] = 1;
            d[i][j] = t1;
        } else {
            chk[i][j] = 2;
            d[i][j] = t2;
        }
        return d[i][j];
    }
}
int main() {
    string s;
    scanf("%s%s", x, y);
    int lx = strlen(x), ly = strlen(y);
    printf("%d\n", f(lx-1, ly-1));
    int i=lx-1, j=ly-1;
    while(i>=0 && j>=0) {
        if(chk[i][j]==0) {
            s = x[i] + s;
            i--; j--;
        } else if(chk[i][j]==1) i--;
        else j--;
    }
    cout << s;
    return 0;
}
