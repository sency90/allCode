#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll M = 1e9+7;
ll dp[200001];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n,k; scanf("%d%d",&n,&k);
		dp[0] = 0;
		ll mx=0, s=0;
		for(int i=1; i<=n; i++) {
			int x; scanf("%d", &x);
			dp[i] = max(dp[i-1]+x, (ll)x);
			s = (s+x+M)%M;
			mx = max(dp[i], mx);
		}

		for(int i=0; i<k; i++) {
			s+=mx;
			s%=M;
			mx=(mx<<1)%M;
		}

		printf("%lld\n", s);

	}
	return 0;
}
