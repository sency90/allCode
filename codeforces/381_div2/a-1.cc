#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
ll d[20];
int n,a,b,c;
ll f(int x) {
    if(x%4==0) return 0;
    else if(x<0) return inf;
    ll &ret = d[x];
    if(ret) return ret;
    else ret = inf;
    return ret = min({f(x-1)+a, f(x-2)+b, f(x-3)+c});
}
int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    if(n%4==0) return 0&puts("0");
    n=12-n%4;
    printf("%lld\n", f(n));
    return 0;
}
