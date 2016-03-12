#include <stdio.h>
int main() {
    int t, n, sum=0, cnt=0, d;
    scanf("%d %d", &t, &n);
    for(int i=0; i<t; i++) {
        scanf("%d", &d);
        if(sum+d > n) break;
        sum += d;
        cnt++;
    }
    printf("%d", cnt);
}
