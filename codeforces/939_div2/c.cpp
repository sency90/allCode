#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		
		int lim = 2*n-1;
		ll s=0LL;
		for(int i=1; i<=n; i++) {
			s += i*(2*i-1);
		}
		printf("%lld %d\n", s, lim);

		int t=0, j=n*2;
		for(int i=0; i<lim; i++) {
			printf("%d %d ", t+1, j>>1);
			for(int u=1; u<=n; u++) printf("%d ", u);
			puts("");
			t^=1; j--;
		}
	}
	return 0;
}
