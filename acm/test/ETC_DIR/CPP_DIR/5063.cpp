#include <stdio.h>
int main() {
    int t, r, e, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &r, &e, &c);
        if(e-c == r) puts("does not matter");
        else if(e-c > r) puts("advertise");
        else puts("do not advertise");
    }
    return 0;
}
