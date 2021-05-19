#include <stdio.h>
int main() {
    int a, b, c;
    int t; scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        printf("Scenario #%d:\n", i);
        scanf("%d %d %d", &a, &b, &c);
        a*=a; b*=b; c*=c;
        if(a+b==c || a+c==b || b+c==a) puts("yes\n");
        else puts("no\n");
    }
}
