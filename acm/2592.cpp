#include <stdio.h>
#include <string.h>
int cnt[101], d, ans, mx=0, sum=0;
int main() {
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<10; i++) {
        scanf("%d", &d);
        sum+=d;
        cnt[d/10]++;
    }
    printf("%d\n",sum/10);
    for(int i=1; i<=100; i++) {
        if(mx < cnt[i]) {
            mx = cnt[i];
            ans = i;
        }
    }
    printf("%d", ans*10);
    return 0;
}
