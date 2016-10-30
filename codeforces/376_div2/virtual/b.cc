#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int n;
    ll sum =0LL;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        ll x;
        scanf("%lld",&x);
        if(x==0) {
            if(sum&1LL) {
                puts("NO");
                return 0;
            } else sum = 0LL;
        }
        sum+=x;
    }
    if(sum&1LL) puts("NO");
    else puts("YES");
    return 0;
}
