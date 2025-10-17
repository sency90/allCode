#include <cstdio>
using namespace std;
int n,l;
int v[200][100];
int main() {
	scanf("%d%d",&n,&l);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &v[i][j]);
			v[j+n][i] = v[i][j];
		}
	}
	int ans=0;
	for(int i=0; i<2*n; i++) {
		int cnt=1,j=1;
		for(; j<n; j++) {
			if(v[i][j-1] == v[i][j]) cnt++;
			else if(v[i][j-1]+1 == v[i][j] && cnt>=l) cnt=1;
			else if(v[i][j-1] == v[i][j]+1 && cnt>=0) cnt=-l+1;
			else break;
		}
		if(j==n && cnt>=0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
