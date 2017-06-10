#include <iostream>
using namespace std;
typedef long long ll;
ll d[41];
ll f(int x) {
    if(x<=1) return 1LL;
    if(d[x]) return d[x];
    return d[x]=f(x-1)+f(x-2);
}
int main() {
    int n,m,s=1;
    scanf("%d%d", &n,&m);
    ll ans=1;
    for(int i=0; i<m; i++) {
        int x; scanf("%d", &x);
        ans*=f(x-s);
        s=x+1;
    }
    if(s<=n) ans*=f(n+1-s);
    printf("%lld\n", ans);
    return 0;
}
