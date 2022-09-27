#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
ll d[20001], a[20001];
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
int main() {
	int m;
	ll n,k; scanf("%lld%d%lld",&n,&m,&k);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
	}

	for(int i=1; i<=n; i++) {
		d[i]=inf;
		ll mx=0, mn=inf;
		for(int j=i; j>=max(1,i-m+1); j--) {
			mx = max(a[j], mx);
			mn = min(a[j], mn);
			d[i] = min(d[i], d[j-1]+k+(ll)(i-j+1)*(mx-mn));
		}
	}

	printf("%lld\n", d[n]);
	return 0;
}
