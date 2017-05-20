#include <stdio.h>
int main() {
    int (*p)[4];

    int (*b1[4])[4];
    int (**b2[4])[4];
    int b3[4];
    b1[0]=p;
    b2[0]=&p;
    b3[0]=(*p)[1];
    return 0;
}
