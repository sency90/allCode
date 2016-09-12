#include <stdio.h>
typedef unsigned int uint;
void interpretBit(uint b, int cnt) {
    if(b==0U) {
        for(int i=0; i<cnt; i++) {
            putchar('0');
        }
    }
    else {
        interpretBit(b/2U, cnt-1);
        printf("%u", b%2U);
    }
}
int main() {
    uint pizza = 13U;
    for(uint i=pizza; i; i=((i-1)&pizza)) {
        interpretBit(i,4);
        puts("");
    }
    return 0;
}
