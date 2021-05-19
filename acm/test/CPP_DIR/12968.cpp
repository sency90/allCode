#include <stdio.h>
int main() {
    int r, c, k;
    scanf("%d%d%d",&r,&c,&k);
    if(r*c%2) {
        if(k==1) puts("1");
        else puts("0");
    } else puts("1");
    return 0;
}
