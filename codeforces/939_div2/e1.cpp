#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int a[200005];
bool ans[200005];
bool check() {
	a[n]=a[0], a[n+1]=a[1], a[n+2]=a[2];
	for(int i=0; i<n; i++) {
		if(a[i]&&a[i+1]&&a[i+2]&&a[i+3]) return true;
		//else if(!a[i]) i+=4;
		//else i++;
	}
	return false;
}
inline int& x(int i) {
	return a[i%n];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int cnt=0;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		if(n<=3) {
			while(true) {
				for(int i=0; i<n; i++) {
					if(a[i]) x(i+1) = max(x(i+1)-a[i],0);
				}
				for(int i=0; i<n; i++) {
					if(!a[i]) goto BRK;
				}
			}
BRK:
			if(n==2) {
				for(int i=0; i<n; i++) {
					if(a[i]) ans[i]=true, cnt++;
				}
			}
			else if(n==3) {
				if(!a[0]&&a[1]) ans[1]=true, cnt++;
				if(!a[1]&&a[2]) ans[2]=true, cnt++;
				if(!a[2]&&a[0]) ans[0]=true, cnt++;
			}
		}
		else {
			while(check()) {
				for(int i=0; i<n; i++) {
					x(i+1) = max(x(i+1)-a[i], 0);
				}
			}
			
			for(int i=0; i<n; i++) {
				if(a[i]&&x(i+1)) {
					x(i+1) = max(x(i+1)-a[i],0);
				}
				else break;
			}

			for(int i=0; i<n; i++) {
				if(!x(i)&&x(i+1)) {
					ans[(i+1)%n] = true, cnt++;
					if(x(i+2)) {
						ll m = x(i+2)/x(i+1);
						if(x(i+3) > m*x(i+2) - m*(m+1)/2*x(i+1)) {
							ans[(i+3)%n] = true, cnt++;
						}
						//if(x(i+3)) i+=4;
						//else i+=3;
					}
					//else i+=2;
				}
				//else i++;
			}
		}
		printf("%d\n", cnt);
		for(int i=0; i<n; i++) {
			if(ans[i]) printf("%d ", i+1);
		}
		puts("");
		memset(ans, false, sizeof(bool)*n);
	}
	return 0;
}
