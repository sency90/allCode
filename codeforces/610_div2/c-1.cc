#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> p;
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n,T,a,b; scanf("%d%d%d%d",&n,&T,&a,&b);
		p.clear(); p.resize(n);
		ll etcnt=0, htcnt=0;
		for(int i=0; i<n; i++) {
			scanf("%d",&p[i].second);
			if(p[i].second) htcnt++;
			else etcnt++;
		}
		for(int i=0; i<n; i++) scanf("%d",&p[i].first);
		p.emplace_back(T+1,0);
		sort(p.begin(), p.end());

		ll ecnt=0, hcnt=0, ans=0;
		for(int i=0; i<=n; i++) {
			ll mandatory_time = ecnt*a + hcnt*b;
			ll has_time = p[i].first-1 - mandatory_time;
			if(has_time>=0) {
				ll canE = min(etcnt-ecnt, has_time/a);
				has_time -= canE*a;
				ll canH = min(htcnt-hcnt, has_time/b);
				ans = max(ans, ecnt+hcnt+canE+canH);
			}

			int k=i;
			while(k<p.size() && p[i].first == p[k].first) {
				if(p[k].second) hcnt++;
				else ecnt++;
				k++;
			}
			i=k-1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
