#include <stdio.h>
void test(int (*a)[10]) {
    printf("test: %lu\n", sizeof(a));
}
int main() {
    int a[10][10];
    printf("main: %lu\n", sizeof(a));
    test(a);
    return 0;
}
