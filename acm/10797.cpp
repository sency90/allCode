#include <stdio.h>
int main() {
    int n=5, t, s = 0, d;
    scanf("%d", &t);
    while(n--) {
        scanf("%d", &d);
        if(d%10==t) s++;
    }
    printf("%d", s);
    return 0;
}
