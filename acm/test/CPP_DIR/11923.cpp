#include <stdio.h>
int v[1001];
int main() {
    int n, c;
    scanf("%d%d",&n,&c);
    int tmp = c;
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int mx = 0;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        tmp = c;
        for(int j=i; j<n; j++) {
            if(tmp<v[j]) continue;
            tmp-=v[j];
            cnt++;
        }
        if(mx < cnt) mx = cnt;
    }
    printf("%d", mx);
    return 0;
}
