#include <cstdio>
using namespace std;
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		int ans = b/3;
		if(b%3) {
			if(b%3+c<3) puts("-1");
			else {
				ans += (b%3+c)/3;
				ans += a;
				if((b%3+c)%3) ans++;
				printf("%d\n", ans);
			}
		}
		else {
			ans += a;
			ans += (c/3);
			if(c%3) ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}
