#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n,x; scanf("%d%d",&n,&x);
		x++;
		a[0] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			a[i] ^= a[i-1];
		}
		int bit=0, ans=-1;
		for(int i=30; i>=0; i--) {
			bit |= (1<<i);
			if(x>>i & 1) {
				if(a[n]&bit) {
					bit ^= (1<<i);
					continue;
				}
				int k=0;
				for(int j=1; j<=n; j++) {
					if((a[j]&bit) == 0) k++;
				}
				ans = max(ans, k);
				bit ^= (1<<i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
