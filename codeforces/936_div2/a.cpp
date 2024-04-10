#include <cstdio>
#include <algorithm>
using namespace std;
int a[200001];
int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);

		int mid = (n-1)/2, ans=1;
		for(int i=mid+1; i<n; i++) {
			if(a[i] == a[mid]) ans++;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
