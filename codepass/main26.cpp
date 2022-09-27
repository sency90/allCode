#include <stdio.h>
#include <algorithm>
#include <cstring>
int dp[3001];
int vsum[3001],v[3001];
const int inf = 0x3f3f3f3f;
inline int min(int x, int y) {
	return x<y?x:y;
}
int cost(int i, int j) { //assert(i<j);
	int mid = (i+1+j)/2;
	int L = mid-i-1;
	int R = j-mid;
	return (L-R)*v[mid] - (vsum[mid-1]-vsum[i]) + (vsum[j]-vsum[mid]);
}
int main() {
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &v[i]);
	}
	std::sort(v+1, v+n+1);
	for(int i=1; i<=n; i++) {
		vsum[i] = vsum[i-1]+v[i];
	}
	int a,b; scanf("%d%d",&a,&b);

	for(int i=0; i<=n; i++) dp[i] = a*vsum[i];
	for(int e=1; e<=n; e++) {
		for(int s=e-1; s>=0; s--) {
			dp[e] = min(dp[e], dp[s]+a*cost(s,e)+b);
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
