#include <stdio.h>
int gcd(int b, int l) {
    int t;
    if((t = b%l) == 0) return l;
    else return gcd(l, t);
}
int main() {
    int a, b, temp; scanf("%d %d", &a, &b);
    if(a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    temp = gcd(a,b);
    printf("%d\n%d\n", temp, a*b/temp);
    return 0;
}
