#include <cstdio>
#include <iostream>
using namespace std;
int a[101];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int k,q;
		cin >> k >> q;
		for(int i=0; i<k; i++) {
			cin >> a[i];
		}
		for(int i=0; i<q; i++) {
			int n; cin >> n;
			if(n<a[0]) printf("%d ", n);
			else printf("%d ", a[0]-1);
		}
		puts("");
	}
}
