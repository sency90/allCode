#include <stdio.h>
int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(n==0) break;
        printf("%d\n", n);
    }
    return 0;
}
