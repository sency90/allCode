#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		ll n,k; cin >> n >> k;
		ll m=0, p=0;
		for(int i=0; ;i++) {
			p += (n+(1LL<<i))/(2LL<<i); //(n+2)/4 , (n+4)/8
			if(k<=p) {
				printf("%lld\n", (2LL<<i)*(k-m)-(1LL<<i)); // 2(k-m)-1 2*(k-m)-2
				break;
			}
			else m=p;
		}
	}
	return 0;
}
