#include <stdio.h>
int main() {
    int a, b, v, ans;
    scanf("%d %d %d", &a, &b, &v);
    ans = (v-b)/(a-b);
    if((v-b)%(a-b)!=0) ans++;
    printf("%d", ans);
    return 0;
}
