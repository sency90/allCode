#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[200005];
bool ans[200005];
int mem_i,n;
bool check(int n, int b) {
	if(b==2) {
		if(a[0]&&a[1]) return true;
		else return false;
	}
	else if(b==3) {
		if(a[0]&&a[1]&&a[2]) return true;
		else return false;
	}
	else {
		a[n]=a[0]; a[n+1]=a[1]; a[n+2]=a[2];
		for(int i=mem_i; i<n; i++) {
			if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]) {
				mem_i = i;
				return true;
			}
		}
		return false;
	}
}
int& x(int i) {
	return a[i%n];
}
bool& anx(int i) {
	return ans[i%n];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		mem_i = 0;
		cin >> n;
		memset(ans, false, n+5);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		int cnt=0;
		if(n==2) {
			while(check(n,2)) {
				a[1] = max(a[1]-a[0],0);
				a[0] = max(a[0]-a[1],0);
			}
			if(!a[0]&&a[1]) ans[1]=true, cnt++;
			else if(a[0]&&!a[1]) ans[0]=true, cnt++;
		}
		else if(n==3) {
			a[n]=a[0];
			while(check(n,3)) {
				for(int i=0; i<n; i++) {
					x(i+1) = max(x(i+1)-x(i),0);
				}
			}

			for(int i=0; i<n; i++) {
				if(!x(i)&&x(i+1)) {
					anx(i+1)=true, cnt++;
					break;
				}
			}
		}
		else {
			while(check(n,4)) {
				for(int i=0; i<n; i++) {
					x(i+1) = max(x(i+1)-x(i),0);
				}
			}

			for(int i=0; i<n; i++) {
				if(a[i]&&a[i+1]) a[i+1] = max(a[i+1]-a[i],0);
				else break;
			}

			for(int i=0; i<n; i++) {
				if(!a[i]&&x(i+1)) {
					anx(i+1)=true, cnt++;
					if(x(i+2)) {
						if(x(i+3)) {
							int m = x(i+2)/x(i+1);
							if(x(i+3) > (ll)m*x(i+2)-(ll)m*(m+1)/2*x(i+1)) {
								anx(i+3) = true, cnt++;
							}
						}
					}
				}
			}
		}

		printf("%d\n", cnt);
		for(int i=0; i<n; i++) {
			if(ans[i]) printf("%d ", i+1);
		}
		puts("");
	}
	return 0;
}
