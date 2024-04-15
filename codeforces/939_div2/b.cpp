#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s;
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		int cnt=0, a;
		for(int i=0; i<n; i++) {
			scanf("%d", &a);
			if(s.count(a)) cnt++;
			else s.insert(a);
		}
		printf("%d\n", cnt);
		s.clear();
	}
	return 0;
}
