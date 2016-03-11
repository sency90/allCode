#include <stdio.h>
int main() {
    int k; scanf("%d", &k);
    int a=1, b=0, tmp;
    for(int i=0; i<k; i++) {
        tmp=a+b;
        a = b;
        b = tmp;
    }
    printf("%d %d", a, b);
    return 0;
}
