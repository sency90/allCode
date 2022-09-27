#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<ll, int> dic;
ll MOD = 1e9+7;
ll f(ll n) {
	if(n<=2) return (int)(n>0);
	else if(dic.count(n)>0) return dic[n];

	if(n%2LL==0) return dic[n] = (f(n/2+1)*f(n/2)%MOD + f(n/2)*f(n/2-1)%MOD)%MOD;
	else return dic[n] = (f(n/2+1)*f(n/2+1)%MOD + f(n/2)*f(n/2)%MOD)%MOD;
}
int main() {
	ll n; scanf("%lld", &n);
	printf("%lld", f(n));
	return 0;
}
