#include <stdio.h>
unsigned long long gcd(unsigned long long b, unsigned long long l) {
    unsigned long long t = b%l;
    if(t == 0) return l;
    else return gcd(l, t);
}

int main() {
    unsigned long long b, l, t;
    scanf("%llu %llu", &b, &l);
    if(b < l) {
        t = b;
        b = l;
        l = t;
    }
    t = gcd(b, l);
    for(unsigned long long i=0; i<t; i++) printf("1");
    return 0;
}
