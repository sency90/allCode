#include <stdio.h>
#include <string.h>
int d[1000001], cnt;
int f(int x) {
    if(d[x] > -1) return d[x];

    int idx = x, cnt=0;
    if(x%10 == 0) cnt++;
    while(x/=10) {
        if(x%10 == 0) cnt++;
    }
    return d[idx] = cnt;
}
int main() {
    memset(d, -1, sizeof(d));
    int t, x, y, sum;
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%d %d", &x, &y);
        for(int i=x; i<=y; i++) {
            sum += f(i);
        }
        printf("%d\n", sum);
    }
    return 0;
}
