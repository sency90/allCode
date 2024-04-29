#include <cstdio>
#include <iostream>
using namespace std;
int a[300005];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n,k; cin >> n >> k;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}

		for(int i=0; i<n; i++) {
			for(int p=0; p<=k; p++) {
				printf("[i:%d,p:%d]:", i,p);
				for(int j=i; p+(j-i)<=k && j<n; j++) {
					printf("(%d,%d) ", j, p+(j-i));
				}
				puts("");
			}
		}
		puts("");
	}
	return 0;
}
