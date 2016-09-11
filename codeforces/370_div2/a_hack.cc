#include <stdio.h>
int main() {
    int n=100000;
    printf("%d\n", n);
    for(int i=0; i<n-1; i++) {
        printf("%d ",1000000000);
    }
    puts("1000000000");
    return 0;
}
