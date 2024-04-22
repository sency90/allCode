#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[200005];
int mem_i=1, n;
bool check() {
	for(int i=mem_i; i<=n; i++) {
		if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]) {
			mem_i = i;
			return true;
		}
	}
	return false;
}
int cnt;
bool ans[200005];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		if(n==2) {
			a[n+1]=a[1];
			while(true) {
				for(int i=1; i<=n; i++) {
					a[i+1] = max(0LL,a[i+1]-a[i]);
				}
				a[1]=a[n+1];
				if(!a[1]||!a[2]) break;
			}
			for(int i=1; i<=n; i++) {
				if(!a[i]&&a[i+1]) ans[i+1]=true, cnt++;
			}
			ans[1] = ans[n+1];
		}
		else if(n==3) {
			a[n+1]=a[1];
			while(true) {
				for(int i=1; i<=n; i++) {
					a[i+1] = max(0LL,a[i+1]-a[i]);
				}
				a[1]=a[n+1];
				if(!a[1]||!a[2]||!a[3]) break;
			}
			for(int i=1; i<=n; i++) {
				if(!a[i]&&a[i+1]) ans[i+1]=true, cnt++;
			}
			ans[1] = ans[n+1];
		}
		else {
			a[n+1]=a[1];
			a[n+2]=a[2];
			a[n+3]=a[3];

			while(check()) {
				for(int i=1; i<=n; i++) {
					a[i+1] = max(0LL,a[i+1]-a[i]);
				}
				a[1] = a[n+1];
				printf("*");
				for(int i=1; i<=n; i++) {
					printf("%lld ", a[i]);
				}
				puts("");
			}
			for(int i=1; i<=n; i++) {
				if(!a[i]&&a[i+1]&&a[i+3]) {
					ans[i+1]=true, cnt++;
					ll m = a[i+2]/a[i+1];
					if(a[i+3] > m*a[i+2]-m*(m+1)/2*a[i+1]) {
						ans[i+3]=true, cnt++;
						i+=3;
					}
					else if(!a[i+2]) i++;
					else if(!a[i+3]) i+=2;
				}
			}
		}
		printf("%d\n", cnt);
		for(int i=1; i<=n; i++) {
			if(ans[i]) printf("%d ", i);
		}
		puts("");
		memset(ans, false, sizeof(bool)*(n+4));
		cnt=0;
	}
	return 0;
}

