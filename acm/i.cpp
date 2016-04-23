#include <stdio.h>
int n, r, g, b;
int f(int h, int r, int g, int b) {
    if(h==n) return 1;
    
}
int main() {
    scanf("%d %d %d %d", &n, &r, &g, &b);
    printf("%d", f(n,r,g,b));
    return 0;
}
