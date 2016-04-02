#include <stdio.h>
int main() {
    int a, b, l=0, r=0;
    scanf("%d %d", &a, &b);
    while(a!=1 || b!=1) {
        if(a<b) {
            if(a==1) {
                r+=b-1;
                b=1;
            } else {
                r+=b/a;
                b-=(b/a)*a;
            }
        } else {
            if(b==1) {
                l+=a-1;
                a=1;
            } else {
                l+=a/b;
                a-=(a/b)*b;
            }
        }
    }
    printf("%d %d", l, r);
    return 0;
}
