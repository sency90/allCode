#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		long long sum = 0LL;
		cin >> s;
		int mi=0,pv=0;
		while(true) {
			int b=-1,e=s.size(),i;
			for(i=mi; i<s.size(); i++) {
				if(b<0 && s[i] == '1') b=i;
				if(b>=0 && s[i] == '0') {
					e=i;
					break;
				}
			}
			bool isin=false;
			for(; i<s.size(); i++) {
				if(s[i] == '1') {
					isin=true;
					mi=i;
					break;
				}
			}
			if(!isin) mi=s.size();
			//printf("** %d,%d,%d\n",b,e,mi);
			sum += (e-b+1+pv)*(mi-e);
			pv += (e-b);
			if(b<0 || mi==s.size()) break;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
