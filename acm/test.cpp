//등차가 d인 등차수열
#include <stdio.h>
int f(int z, int x, int d, int n) {
    if(n==1) return z;
    return f(z+x+d, x+d, d, n-1);
}
int main() {
    int n = 3;
    printf("%d", f(4, 3, 2, n));
    return 0;
}
