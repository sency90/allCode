#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool dp[31][30001], ans[8];
int v[31], w[8];
int main() {
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &v[i]);
	}

	int m; scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &w[i]);
	}

	dp[0][15000] = true;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=30000; j++) {
			if(dp[i-1][j]) {
				dp[i][j-v[i]] = true;
				dp[i][j] = true;
				dp[i][j+v[i]] = true;
			}
		}
	}

	for(int j=0; j<=15000; j++) {
		if(dp[n][j+15000]) {
			for(int i=0; i<m; i++) {
				if(w[i]==j) ans[i] = true;
			}
		}
	}

	for(int i=0; i<m; i++) {
		if(ans[i]) printf("Y ");
		else printf("N ");
	}
	puts("");
	return 0;
}
