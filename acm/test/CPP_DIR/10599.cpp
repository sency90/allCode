#include <stdio.h>
int main() {
    int a, b, c, d;
    while(true) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==0 && b==0 && c==0 && d==0) return 0;
        printf("%d %d\n", c-b, d-a);
    }
    return 0;
}
