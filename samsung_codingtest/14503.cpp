#include <cstdio>
using namespace std;
int n,m,r,c,d;
int v[50][50];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int ans=0;
bool chk[50][50];
void go(int x, int y, int d) {
	if(v[x][y] == 0 && !chk[x][y]) {
		ans++;
		chk[x][y] = true;
	}

	int wall_cnt=0, unclear_cnt=0;
	for(int i=0; i<4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=m) continue;
		if(v[nx][ny]==1) wall_cnt++;
		if(v[nx][ny]==0 && !chk[nx][ny]) unclear_cnt++;
	}
	if(unclear_cnt==0) {
		int nd = (d+2)%4;
		int nx=x+dx[nd];
		int ny=y+dy[nd];

		if(v[nx][ny]==0) {
			go(nx,ny,d);
			return;
		}
		else return;
	}
	else {
		for(int i=1; i<=4; i++) {
			int nd = (d-i+4)%4;
			int nx = x+dx[nd];
			int ny = y+dy[nd];
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(v[nx][ny]==0 && !chk[nx][ny]) {
				go(nx,ny,nd);
				return;
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&r,&c,&d);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	go(r,c,d);
	printf("%d\n", ans);
	return 0;
}
