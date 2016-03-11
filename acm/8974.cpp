#include <stdio.h>
#include <string.h>
int main() {
    int a, b, sum[1001], k=0, p=1;
    scanf("%d %d", &a, &b);
    memset(sum, 0, sizeof(sum));
    while(p <= b) {
        k++;
        for(int j=1; j<=k; j++) {
            sum[p] = sum[p-1]+k;
            if(p++==b) break;
        }
    }
    printf("%d",sum[b]-sum[a-1]);
    return 0;
}
