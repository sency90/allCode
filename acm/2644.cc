#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int b;
vector<int> v[101];
bool chk[101];
int ans[101];
void dfs(int x, int depth) {
	chk[x] = true;
	ans[x] = depth;
	if(ans[b]!=-1) return;
	for(int i=0; i<v[x].size(); i++) {
		int y = v[x][i];
		if(chk[y]) continue;
		dfs(y, depth+1);
	}
}
int main() {
	memset(ans, -1, sizeof(ans));
	int n; scanf("%d", &n);
	int a; scanf("%d%d",&a,&b);
	int m; scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(a, 0);
	printf("%d\n", ans[b]);
	return 0;
}
