#include <stdio.h>
int main() {
    int p, k, n;
    scanf("%d", &p);
    for(int i=0; i<p; i++) {
        scanf("%d %d", &k, &n);
        printf("%d %d %d %d\n",k,n*(n+1)/2,n*n,n*(n+1));
    }
    return 0;
}
