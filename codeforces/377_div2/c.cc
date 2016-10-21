#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[3],ans=0LL;
int main() {
    for(int i=0; i<3; i++) scanf("%lld",&a[i]);
    sort(a,a+3);
    ll b=a[2]-1LL;
    if(a[1]==b||a[1]==b+1LL) {
    } else ans+=b-a[1];
    if(a[0]==b||a[0]==b+1LL) {
    } else ans+=b-a[0];
    printf("%lld\n", ans);
    return 0;
}
