#include <cstdio>
using namespace std;
int n,l;
int v[202][102];
bool chk[202];
inline int ABS(int x) {
	return x<0?-x:x;
}
constexpr int D = 1;
constexpr int U = 2;
int updown[102];
int main() {
	scanf("%d%d",&n,&l);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &v[i][j]);
			v[n+j][i] = v[i][j];
		}
	}
	for(int i=0; i<2*n; i++) {
		for(int j=0; j<n-1; j++) {
			if(ABS(v[i][j]-v[i][j+1])>=2) {
				chk[i] = true;
				break;
			}
		}
	}
	int ans = 0;
	for(int i=0; i<2*n; i++) {
		if(chk[i]) continue;
		for(int j=0; j<n; j++) updown[j] = 0;

		for(int j=0; j<n-1; j++) {
			if(v[i][j] == v[i][j+1]+1) { //down
				int cnt=1;
				for(int k=j+2,w=0; w<l-1 && k<n; w++,k++) {
					if(v[i][j+1] == v[i][k]) cnt++;
				}
				if(cnt == l) {
					for(int k=j+1,w=0; w<l && k<n; w++,k++) {
						updown[k] |= D;
					}
					j += l-1;
				}
				else goto BRK;
			}
		}
		for(int j=n-1; j>=1; j--) {
			if(v[i][j-1]+1 == v[i][j]) {//up
				int cnt=1;
				for(int k=j-2,w=0; w<l-1 && k>=0; w++,k--) {
					if(v[i][j-1] == v[i][k]) cnt++;
				}
				if(cnt == l) {
					for(int k=j-1,w=0; w<l && k>=0; w++,k--) {
						if(updown[k]>0) {
							goto BRK;
						}
					}
					j -= l-1;
				}
				else goto BRK;
			}
		}
		ans++;
BRK:;
	}
	printf("%d\n", ans);
	return 0;
}
