#include <stdio.h>
int main() {
    int a, b, c, d, p, t;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&p);
    if(p <= c) {
        if(a*p < b) printf("%d", a*p);
        else printf("%d", b);
    } else {
        t = (p-c)*d+b;
        if(t < a*p) printf("%d", t);
        else printf("%d", a*p);
    }
}
