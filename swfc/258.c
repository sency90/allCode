#include <stdio.h>
#include <stdarg.h>
void my_test(int a, ...) {
    //[1] print 3.14
    printf("f = > %0.2f\n", **(double**)(&a+1));
    //[2] print "BIN" with calling f1 function indirectly
    printf("%s", (*((*(char*(***)())(&a+2))[0]))() + 2);
    //printf("%s", (*(char *(***)())(&a+2))[0]() + 2);
    //printf("%s", (*(char *(***)())(&a+2))[1]() + 2);
}

char *f1(void) {
    return "CABIN";
}
char *f2(void) {
    return "LOGO";
}
int main() {
    double d = 3.14;
    char *(*fa[2])() = {f1, f2};
    my_test(1,&d,fa);
    return 0;
}
