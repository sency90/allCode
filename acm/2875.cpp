#include <stdio.h>
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int s = (n+m-k)/3;
    while(true) {
        if(s*2 <= n && s <= m) break;
        s--;
    } printf("%d", s);
}
