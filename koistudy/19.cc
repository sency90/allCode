#include <stdio.h>
char a[16],b[16];
int main() {
    scanf("%[^-]-%s", a,b);
    printf("%s%s", a,b);
    return 0;
}
