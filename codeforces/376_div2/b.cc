#include <cstdio>
using namespace std;
int main() {
    int n;
    long long d,ans=0LL;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld",&d);
        if(d==0LL) {
            if(ans&1LL) {
                puts("NO");
                return 0;
            } else ans=0LL;
        }
        ans+=d;
    }
    if(ans&1LL) puts("NO");
    else puts("YES");
    return 0;
}
