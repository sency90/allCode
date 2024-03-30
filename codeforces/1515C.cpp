#include <cstdio>
#include <set>
using namespace std;
int h[100001];
set<pair<int,int>> s;
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n,m,x; scanf("%d%d%d",&n,&m,&x);
		for(int i=0; i<n; i++) {
			scanf("%d", &h[i]);
		}
		for(int i=0; i<m; i++) {
			s.emplace(0,i+1);
		}
		puts("YES");
		for(int i=0; i<n; i++) {
			auto it = s.begin();
			int w = it->first;
			int idx = it->second;
			s.erase(it);
			s.emplace(w + h[i], idx);
			printf("%d ", idx);
		}
		puts("");
		s.clear();

	}
	return 0;
}
