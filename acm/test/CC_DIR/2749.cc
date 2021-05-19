//@ 2020.0520.1044
//fibonacci: f(n) = f(n-1) + f(n-2);
//           f(2n)   = f(n-1)*f(n) + f(n)*f(n+1)
//           f(2n+1) = f(n-1)*f(n+1) + f(n)*f(n+2)
//           f(x) -> k = x/2
//                   f(x) = f(k-1)*f(k + (x%2==1)?1:0) + f(k)*f(k+1 + (x%2==1)?1:0);

#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M = 1e6;
map<ll, ll> dic;
ll f(ll x) {
    if(dic.count(x)>0) return dic[x];

    ll u=x/2LL, v=x%2LL;
    return dic[x] = (f(u-1)*f(u +v) + f(u)*f(u+1 +v))%M;
}
int main() {
    ll k; scanf("%lld", &k);
    dic[0]=0; dic[1]=1; dic[2]=1; dic[3]=2;
    printf("%lld", f(k));
    return 0;
}
