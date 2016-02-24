#include <stdio.h>
int spow(int x, int y) {
    int res = 1;
    for(int i=0; i<y; i++) res = (res*x)%10;
    return res;
}
int main() {
    int a, b, n, t;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", (t = spow(a%10, (b-1)%4+1)) == 0? 10:t);
    } return 0;
}
