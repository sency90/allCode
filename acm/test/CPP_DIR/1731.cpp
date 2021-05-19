#include <stdio.h>
int v[51];
int main() {
    int n, ans, d=0, r=1;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", v+i);
    }
    if(v[2]-v[1]==v[1]-v[0]) d=v[1]-v[0];
    else r=v[1]/v[0];
    if(d>0) ans = v[n-1]+d;
    else ans = v[n-1]*r;
    printf("%d", ans);
    return 0;
}
