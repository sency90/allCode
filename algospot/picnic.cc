#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
typedef pair<int,int> pii;
int n,m,ans;
bool chk[11];
void dfs(int x, vector<pii> & w) {
	if(x==n) {
		if(w.size() == (n>>1)) ans++;
		return;
	}
	if(!chk[x]) {
		chk[x] = true;
		for(int i=0; i<v[x].size(); i++) {
			if(chk[v[x][i]]) continue;
			chk[v[x][i]] = true;
			w.push_back(pii(x, v[x][i]));
			dfs(x+1, w);
			w.pop_back();
			chk[v[x][i]] = false;
		}
		chk[x] = false;
	}
	dfs(x+1, w);
}
int main() {
	vector<pii> w;
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		v.resize(10, vector<int>());
		memset(chk,false,sizeof(chk));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0; i<m; i++) {
			int x,y;
			scanf("%d%d", &x,&y);
			if(x<y) v[x].push_back(y);
			else v[y].push_back(x);
		}

		dfs(0,w);
		printf("%d\n", ans);
	}

	return 0;
}
