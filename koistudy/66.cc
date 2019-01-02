#include <stdio.h>
int main() {
    int a; scanf("%d", &a);
    printf("%s\n", a<0?"minus":"plus");
    printf("%s\n", (a&1)?"odd":"even");
    return 0;
}
