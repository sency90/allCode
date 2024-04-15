#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ull a,b,m; 
		scanf("%llu%llu%llu",&a,&b,&m);

		ull ans = (m/a)+1ULL;
		ans += (m/b)+1ULL;
		printf("%llu\n", ans);
	}
	return 0;
}

