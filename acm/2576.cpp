#include <stdio.h>
#define MIN(a,b) (a<b?a:b)
int main() {
    short in, sum=0, min=101;
    for(char i=0; i<7; i++) {
        scanf("%hd", &in);
        if(in%2) {
            sum += in;
            min = MIN(min,in);
        }
    }
    if(min != 101) printf("%hd\n", sum);
    else min = -1;
    printf("%hd\n", min);
    return 0;
}
