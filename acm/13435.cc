#include <cstdio>
using namespace std;
int main() {
    int n,m; scanf("%d%d",&n,&m);
    if(n==m) return 0&printf("%d", n);
    if(m&1) {
        long long b=(m+1)/2, s=m/2, ans;
        if(n&1) ans = s*(n/2)+b*(n/2+1);
        else ans = (s+b)*(n/2);
        printf("%lld", ans);
    } else {
        int d = m/2;
        printf("%lld", (long long)d*n);
    }
    return 0;
}
