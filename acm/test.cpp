#include <stdio.h>
int main() {
    for(int i=0; i<10; i++) {
        printf("%d %d %d %d\n", 8>>i, i>>8, 8<<i, i<<8);
    }
}
