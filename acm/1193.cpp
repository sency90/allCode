#include <stdio.h>

int calc( int x ) {
    return (x*x-x+2) / 2;
}
// 1, 2, 4, 7, 11, 16, 22
int main() {
    int i=0, x, idx; scanf("%d", &x);
    for(i=1;;i++) {
        if( x < calc(i) ) break;
    }

    printf("%d/%d\n", calc(i)-x, x-calc(i-1)+1);
    return 0;
}
