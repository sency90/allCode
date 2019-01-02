#include <stdio.h>
int gcd(int b, int l) {
    return l==0?b:gcd(l,b%l);
}
int main() {
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    int g = gcd(a,b);
    int k = a*b/g;
    g = gcd(k,c);
    printf("%d\n", k*c/g);
    return 0;
}
