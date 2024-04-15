#include <cstdio>
using namespace std;
char a[300001];
int s[300001];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int n; scanf("%d", &n);
		scanf("%s", a);
		for(int i=0; i<n; i++) {
			a[i] = a[i]-'0';
			s[i+1] = s[i]+a[i];
		}
		int m = n/2;
		int t;
		if(n&1) t=1;
		else t=-1;
		for(int i=0; i<n; i++) {
			int j=m+t*i;
			bool good = false;
			if(j>=0) {
				if(j-s[j]>=s[j] && (n-s[n]-(j-s[j]))<=(s[n]-s[j])) {
					printf("%d\n", j);
					break;
				}
				good = true;
			}
			j=m-t*i;
			if(j<=n) {
				if(j-s[j]>=s[j] && (n-s[n]-(j-s[j]))<=(s[n]-s[j])) {
					printf("%d\n", j);
					break;
				}
				good = true;
			}
			if(!good) break;
		}
	}
	return 0;
}
