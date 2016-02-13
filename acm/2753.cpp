#include <stdio.h>
int main() {
    short y, res;
    scanf("%hd", &y);
    if(0 == y % 4) {
        if(0 == y % 100) {
            if(0 == y % 400) {
                res = 1;
            } else res = 0;
        } else res = 1;
    } else res = 0;
    printf("%hd\n", res);
    return 0;
}
