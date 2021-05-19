#include <stdio.h>

int calc( int x ) {
    return (x*x-x+2) / 2;
}

int main() {
    int i=0, x, idx; scanf("%d", &x);
    for(i=1;;i++) {
        if( x < calc(i) ) break;
    }

    if(i%2 == 0) {
        printf("%d/%d\n", calc(i)-x, x-calc(i-1)+1);
    } else {
        printf("%d/%d\n", x-calc(i-1)+1, calc(i)-x);
    }
    return 0;
}
