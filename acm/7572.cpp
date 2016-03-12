#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    n+=56;
    n = n%60;
    printf("%c%d", n%12+'A',n%10);
    return 0;
}
