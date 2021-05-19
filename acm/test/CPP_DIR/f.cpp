#include <stdio.h>
int main() {
    int n, i, t=0;
    scanf("%d", &n);
    for(i=1;;i++) {
        t += 2*i*i - 2*i + 1;
        if(t>n) break;
    }
    printf("%d", i-1);
    return 0;
}
