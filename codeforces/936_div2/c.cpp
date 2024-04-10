#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> v;
int chk[100001];
int C = 1, N, K, CC;
int dfs(int x) {
	int subtree = 1;
	chk[x] = C;
	for(int y: v[x]) {
		if(chk[y] == C) continue;
		subtree += dfs(y);
	}
	if(K>=1 && subtree >= CC && N-subtree >= CC) {
		N-=subtree;
		K--;
		return 0;
	}
	return subtree;
}
bool possible(int n, int k, int cc) {
	N = n;
	K = k;
	CC = cc;
	dfs(1);
	return K==0;
}
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n,k; scanf("%d%d",&n,&k);
		int a,b;
		v.clear(); v.resize(n+1, vector<int>());
		for(int i=0; i<n-1; i++) {
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int hi = n/(k+1), lo=1;
		if(hi==1) puts("1");
		else {
			while(lo <= hi) {
				int mid = (lo+hi)/2;
				if(possible(n, k, mid)) lo = mid+1;
				else hi = mid-1;
				C++;
			}
			printf("%d\n", lo-1);
		}
	}
	return 0;
}
