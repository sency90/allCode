#include <stdio.h>
int main() {
    int n, m, i;
    scanf("%d%d", &n,&m);
    for(i=0; ; i++) {
            if(n*i/m > 0) break;
        }
    printf("%d", (i-1)*n);
    return 0;
}
