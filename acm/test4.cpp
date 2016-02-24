#include <stdio.h>
int main() {
    for(int i=1; i<=20; i++) {
        printf("%d %d\n", i, (i-1)%4+1);
    }
    return 0;
}
