#include <stdio.h>
int main() {
    int x, y;
    scanf("%d %d",&x,&y);
    printf("%d %d\n", x^y, y^x);
}
