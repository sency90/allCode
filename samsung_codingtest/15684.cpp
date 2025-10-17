#include <cstdio>
using namespace std;
int n,m,h;
int nouse[32][12];
bool ladder[32][12];
void regi_ladder(int x, int y) {
	nouse[x][y-1]++;
	nouse[x][y]++;
	nouse[x][y+1]++;
	ladder[x][y] = true;
}
void unregi_ladder(int x, int y) {
	nouse[x][y-1]--;
	nouse[x][y]--;
	nouse[x][y+1]--;
	ladder[x][y] = false;
}
bool dfs(int th, int x, int y) {
	if(th==0) {
		for(int j=1; j<n; j++) {
			int s=j;
			for(int i=1; i<=h; i++) {
				if(ladder[i][s]) s++;
				else if(ladder[i][s-1]) s--;
			}
			if(s!=j) return false;
		}
		return true;
	}

	int j=y+1;
	for(int i=x; i<=h; i++) {
		for(; j<n; j++) {
			if(nouse[i][j]>0) continue;
			regi_ladder(i,j);
			if(dfs(th-1,i,j)) {
				return true;
			}
			unregi_ladder(i,j);
		}
		j=0;
	}

	return false;
}
int main() {
	scanf("%d%d%d",&n,&m,&h);
	for(int i=0; i<m; i++) {
		int x,y; scanf("%d%d", &x,&y);
		regi_ladder(x,y);
	}
	for(int i=0; i<=3; i++) {
		if(dfs(i,1,0)) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
