#include <stdio.h>
int main() {
    int a, b, c;
    while(true) {
        scanf("%d %d %d", &a, &b, &c);
        if(a==0 && b==0 && c==0) return 0;
        if(b-a == c-b) printf("AP %d\n", c+b-a);
        else printf("GP %d\n", c*(b/a));
    }
}
