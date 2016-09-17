#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long a,b,c,d,e;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);

    long long l=max(a,c), r=min(b,d);
    if(r<l) puts("0");
    else {
        if(l<=e && e<=r) printf("%lld\n",r-l);
        else printf("%lld\n", r-l+1LL);
    }
    return 0;
}
