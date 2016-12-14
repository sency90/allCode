#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f;
ll d[10];
int main() {
    ll n,a,b,c,ans=inf;
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
    memset(d,0x3f,sizeof(d));
    d[0]=0LL;
    n%=4LL;
    if(n==0LL) return 0&puts("0");
    for(int i=1; i<=9; i++) {
        if(i>=1) d[i]=min(d[i],d[i-1]+a);
        if(i>=2) d[i]=min(d[i],d[i-2]+b);
        if(i>=3) d[i]=min(d[i],d[i-3]+c);
        if((n+i)%4==0) ans=min(ans,d[i]);
    }
    printf("%lld", ans);
    return 0;
}
