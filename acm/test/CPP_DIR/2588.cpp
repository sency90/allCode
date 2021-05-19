#include <stdio.h>
int ten(char x) {
    int r = 1;
    for(char i=0; i<x; i++) r *= 10;
    return r;
}
int main() {
    char v[2][3], c, i=3, j;
    while((c=getchar())&'0') v[0][--i] = c-'0';
    i=3;
    while((c=getchar())&'0') v[1][--i] = c-'0';

    int ans[4] = {0,};
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            ans[i] += (((int)v[0][j] * v[1][i])*ten(j));
        } ans[3]+=(ans[i]*ten(i));
    }
    for(i=0; i<4; i++) printf("%d\n", ans[i]);
    return 0;
}
