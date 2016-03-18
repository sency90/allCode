#include <stdio.h>
int main() {
    int a, b;
    while(true) {
        scanf("%d %d", &a, &b);
        if(a==0 && b==0) return 0;
        if(a>b) puts("Yes");
        else puts("No");
    }
}
