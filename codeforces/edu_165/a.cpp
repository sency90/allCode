#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int p[51];
bool chk[51];
int dfs(int x) {
	if(chk[x]) return 0;
	chk[x] = true;
	return dfs(p[x])+1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i=1; i<=n; i++) {
			int x;
			cin >> x;
			p[i] = x;
		}
		memset(chk,false,sizeof(chk));
		int mn = 0x3f3f3f3f;
		for(int i=1; i<=n; i++) {
			if(chk[i]) continue;
			int res = dfs(i);
			mn = min(res, mn);
		}
		if(mn!=2) puts("3");
		else printf("%d\n", mn);
	}
	return 0;
}
