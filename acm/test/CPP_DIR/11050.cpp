#include <stdio.h>
int main() {
    int n, k, res=1; scanf("%d %d", &n, &k);
    if(n-k < k) k=n-k;
    for(int i=0; i<k; i++) {
        res = res * (n-i) / (i+1);
    }
    printf("%d", res);
    return 0;
}
