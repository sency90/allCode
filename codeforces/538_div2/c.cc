#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
int minFactor[1000001];
map<ll, ll> dic;
vector<ll> v;
bool isNotPrime[1000001];
int main() {
    ll n,b;
    isNotPrime[0]=isNotPrime[1]=true;
    for(int i=2; i<=1000; i++) {
        if(isNotPrime[i]) continue;
        for(int j=i*i; j<=1000000; j+=i) {
            isNotPrime[j]=true;
        }
    }
    scanf("%lld %lld", &n,&b);

    ll mx = b;
    for(ll i=2LL; i*i<=mx; i++) {
        if(isNotPrime[i]) continue;
        while(b%i==0) {
            dic[i]++;
            b/=i;
        }
    }
    if(b!=1 && b<=1000000 && !isNotPrime[b]) {
        dic[b]++;
    } else if(b>1000000) dic[b]++;

    if(dic.empty()) dic[mx] = 1;

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
