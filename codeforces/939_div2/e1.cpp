#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		a[n] = a[0];

		int cnt=0;
		while(true) {
			bool do_more = false;
			cnt=0;
			int pa;
			for(register int i=0; i<n; i++) {
				if(a[i]==0) continue;
				if(a[i+1]==0) {
					cnt++;
					continue;
				}
				if(a[i]==0 || a[i+1]==0) continue;
				pa = a[i+1];
				a[i+1]-=a[i];
				if(a[i+1]<0) a[i+1]=0;
				do_more = true;
			}
			a[0] = a[n];
			if(!do_more) break;
		}
		printf("%d\n", cnt);
		for(register int i=0; i<n; i++) {
			if(a[i]) printf("%d ", i+1);
		}
		puts("");
	}
	return 0;
}
