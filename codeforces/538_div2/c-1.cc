#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> dic;
int main() {
    ll n,b;
    scanf("%lld %lld", &n,&b);
    ll tmpB = b;
    for(ll i=2LL; i*i<=tmpB; i++) {
        while(b%i==0) {
            dic[i]++;
            b/=i;
        }
    }

    if(dic.empty()) dic[tmpB] = 1;

    ll N = n;
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(auto &it : dic) {
        ll x = it.first;
        ll cnt = it.second;
        ll sum = 0;
        while(n!=0) {
            sum += ll(n/x);
            n/=x;
        }
        ans = min(ans, sum/cnt);
        n=N;
    }
    printf("%lld", ans);
    return 0;
}
