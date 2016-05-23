#include <stdio.h>
#include <algorithm>
using namespace std;
int v[200000], n, c, ans=0;
void bs(int l, int r) {
    if(l>r) return;
    int m = (l+r)/2;
    int last=v[0], cnt=1;
    for(int i=1; i<n; i++) {
        if(v[i]-last>=m) {
            if(++cnt >= c) break;
            last=v[i];
        }
    }
    if(cnt>=c) {
        if(ans<m) ans=m;
        bs(m+1,r);
    } else bs(l,m-1);
}
int main() {
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v,v+n);
    bs(1,v[n-1]-v[0]);
    printf("%d", ans);
    return 0;
}
