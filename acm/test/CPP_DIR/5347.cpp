#include <stdio.h>
int gcd(int b, int l) {
    int t = b%l;
    if(t == 0) return l;
    else return gcd(l, t);
}
int main() {
    int b, l, n, t;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &b, &l);
        if(b<l) {
            t = b;
            b = l;
            l = t;
        }
        t = gcd(b,l);
        printf("%lld\n", (long long)b*l/t);
    }
    return 0;
}
