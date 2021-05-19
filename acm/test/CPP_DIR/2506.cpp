#include <stdio.h>
int main() {
    int n, d, s=0, ps=0, i=0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        if(d==1) ps+=++i;
        else {
            i=0;
            s += ps;
            ps = 0;
        }
    }
    s+=ps;
    printf("%d", s);
    return 0;
}
