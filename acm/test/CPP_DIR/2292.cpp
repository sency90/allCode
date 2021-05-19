#include <stdio.h>
int calc(int x) {
    return 3*x*(x-1)+1;
}
int main() {
    int x; scanf("%d", &x);
    if(1 == x) {
        printf("1\n");
        return 0;
    }
    int i = 2;
    for( ; ; i++) {
        if(x <= calc(i)) break;
    }
    printf("%d\n", i);
    return 0;
}
