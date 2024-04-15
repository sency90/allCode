#include <cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n,x; scanf("%d%d",&n,&x);
		x++; 
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			a[i]^=a[i-1];
		}
		int bit = 0, mx=-1;
		for(int i=30; i>=0; i--) {
			bit |= (1<<i);
			if((x>>i) & 1) {
				if((a[n]&bit) == 0) {
					int k=0;
					for(int i=1; i<=n; i++) {
						if((a[i]&bit) == 0) k++;
					}
					mx = max(mx, k);
				}
				bit ^= (1<<i);
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}
