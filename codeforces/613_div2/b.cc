#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
ll dp[100010];
int chk[200020];

ll f(int x, int z) {
	ll &ret = dp[x];
	if(x==1) return ret=v[x];
	if(chk[x] == z) return ret;

	return ret = max(0LL, f(x-1,z)) + v[x];
}
int main() {
	int tc; scanf("%d", &tc);
	for(int z=1; z<=tc; z++) {
		int n; scanf("%d", &n);
		v.clear(); v.resize(n+1, 0LL);
		ll yasser=0LL, adel=0LL;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &v[i]);
			yasser += v[i];
		}

		f(n-1,z);
		for(int i=1; i<=n-1; i++) {
            adel = max(adel, dp[i]);
        }

		v[1]=0LL;
		f(n,z+tc);

		for(int i=2; i<=n; i++) {
            adel = max(adel, dp[i]);
        }
		if(yasser > adel) puts("YES");
		else puts("NO");
	}
	return 0;
}
