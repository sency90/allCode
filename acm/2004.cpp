#include <stdio.h>
#define min(a, b) (a<b?a:b)
long long calc(int x, int deno) {
    long long cnt = 0;
    while((x/=deno) > 0) cnt += x;
    return cnt;
}
int main() {
    int n, m;
    long long cnt5 = 0, cnt2 = 0;
    scanf("%d %d", &n, &m);

    if(m == 0 || n == m) {
        printf("0\n");
        return 0;
    }

    cnt5 += calc(n, 5);
    cnt5 -= calc(m, 5) + calc(n-m, 5);
    cnt2 += calc(n, 2);
    cnt2 -= calc(m, 2) + calc(n-m, 2);

    printf("%lld\n", min(cnt5,cnt2));
    return 0;
}
