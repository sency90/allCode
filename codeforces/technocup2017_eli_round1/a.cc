#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> ans;
ll a, b;
bool f(ll x) {
    if(x==a) {
        ans.push_back(x);
        return true;
    }
    if(x<=0LL) return false;
    bool p=false,q=false;
    if(x%10==1LL) {
        p=f(x/10);
        if(p) ans.push_back(x);
    } else if(!(x&1LL)){
        q=f(x>>1);
        if(q) ans.push_back(x);
    } else return false;
    return p|q;
}
int main() {
    scanf("%lld%lld",&a,&b);
    if(f(b)) {
        puts("YES");
        printf("%lu\n",ans.size());
        for(auto &p:ans) {
            printf("%lld ",p);
        }
    } else puts("NO");
    return 0;
}
