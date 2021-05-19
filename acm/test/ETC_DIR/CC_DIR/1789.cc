#include <cstdio>
using namespace std;
using ll = long long;
ll findN(ll s) {
	ll lo=1, hi=4294967295LL;

	while(lo<=hi) {
		ll mid = (lo+hi)/2;
		if(mid*(mid+1) <= 2*s) lo = mid+1;
		else hi = mid-1;
	}
	return lo-1;
}
int main() {
	ll s; scanf("%lld", &s);
	ll n = findN(s);
	if(s - n*(n+1)/2 <= n) printf("%lld", n);
	else printf("%lld", n+1);
	return 0;
}
