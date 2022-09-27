#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int m[101], c[101], dp[101][10001];
int main() {
	int N,M; scanf("%d%d", &N,&M);
	for(int i=1; i<=N; i++) scanf("%d", &m[i]);
	for(int i=1; i<=N; i++) scanf("%d", &c[i]);

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int ans = 0x3f3f3f3f;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=10000; j++) {
			if(dp[i-1][j]>=0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if(dp[i][j]>=M) ans = min(ans, j);

				dp[i][j+c[i]] = max(dp[i][j+c[i]], dp[i-1][j]+m[i]);
				if(dp[i][j+c[i]]>=M) ans = min(ans, j+c[i]);
			}
		}
	}

	printf("%d", ans);
	return 0;
}
