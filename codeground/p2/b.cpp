#include <stdio.h>
#include <algorithm>
using namespace std;
int p[10005],q[10005],d[10005];
int main() {
    int t,n;
    setbuf(stdout, NULL);
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        printf("Case #%d\n", z);
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &p[i]);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d", &q[i]);
        }
        d[1] = max(p[1],q[1]);
        for(int i=2; i<=n; i++) {
            d[i] = max(d[i-1]+p[i], d[i-2]+q[i]);
        }
        printf("%d\n", d[n]);
    }
    return 0;
}
