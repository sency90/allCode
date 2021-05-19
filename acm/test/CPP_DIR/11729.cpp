#include <stdio.h>
int spow(int a, int b) {
    int r = 1;
    for(int i=0; i<b; i++) r*=a;
    return r;
}
void f(int k, int x, int y) {
    if(k==0) return;
    f(k-1, x, 6-x-y);
    printf("%d %d\n", x, y);
    f(k-1, 6-x-y, y);
}
int main() {
    int n; scanf("%d", &n);
    printf("%d\n", spow(2,n)-1);
    f(n, 1, 3);
    return 0;
}
