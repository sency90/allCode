#include <stdio.h>
void printDecimal(int a, int b) {
    int iter = 0;
    while(a>0) {
        if(iter++ == 1) putchar('.');
        printf("%d", a/b);
        if(a%b == 0) break;
        else a=a%b*10;

        if(iter == 15) break;
    }
}
int main() {
    int a, b;
    scanf("%d%d",&a,&b);
    printDecimal(a,b);
    return 0;
}
