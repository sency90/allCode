#include <stdio.h>
int main() {
    int a, b;
    while(true) {
        scanf("%d %d", &a, &b);
        if(a==0 && b==0) return 0;
        if(a==0 || b==0) puts("neither");
        else if(b%a==0 && b/a!=0) puts("factor");
        else if(a%b==0 && a/b!=0) puts("multiple");
        else puts("neither");
    }
    return 0;
}
