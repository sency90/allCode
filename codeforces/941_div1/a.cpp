#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int a[200005];
set<int> s;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc; 
	while(tc--) {
		int n; cin >> n;
		s.clear();
		for(int i=0; i<n; i++) {
			int x; cin >> x;
			s.insert(x);
		}

		int py = 0;
		int tog = 0;
		int winner = -1;
		for(int y: s) {
			int diff = y-py;
			if(diff>1) {
				winner = tog;
				break;
			}
			py = y;
			tog ^= 1;
		}
		if(winner<0) {
			if(s.size()%2==0) winner=1;
			else winner =0;
		}

		if(winner==0) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
