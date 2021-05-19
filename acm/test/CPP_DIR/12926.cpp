#include <stdio.h>
#include <algorithm>
using namespace std;
const long long MOD = 1000000007;
int q[101];
int n, m, cur=0;
long long a, b, x0;
long long f(long long x, int i) {
    if(i==0) return x;
    cur++;
    return f((x*a+b)%MOD, i-1);
}
int main() {
    scanf("%d%lld%lld%lld%d",&n,&x0,&a,&b,&m);
    for(int i=0; i<m; i++) {
        scanf("%d", &q[i]);
    }
    sort(q,q+m);

    long long pans=x0, ans, res=0;
    for(int i=0; i<m; i++) {
        if(q[i]==0) {
            res += x0;
            continue;
        }
        ans = f(pans,q[i]-cur);
        res += ans;
        pans = ans;
    }
    printf("%lld", res);
    return 0;
}
