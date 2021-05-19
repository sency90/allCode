#include <stdio.h>
#include <algorithm>
int main() {
    int d[15000], n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &d[i]);
    }
    std::sort(d, d+n);
    int a=0, b=n-1, t, cnt=0;
    while(a<b) {
        if((t=d[a]+d[b]) == m) {
            cnt++;
            a++;
            b--;
        } else if(t < m) a++;
        else b--;
    }
    printf("%d\n", cnt);
    return 0;
}
