#include <stdio.h>
int cnt[42];
int main() {
    int d, ans=0;
    while(scanf("%d", &d)!=EOF) {
        cnt[d%42]++;
    }
    for(int i=0; i<42; i++) {
        if(cnt[i]) ans++;
    }
    printf("%d", ans);
    return 0;
}
