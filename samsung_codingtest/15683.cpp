#include <cstdio>
using namespace std;
int v[8][8];
int n,m;
struct Coord{
	int x,y;
};
Coord cctv_list[8];
int cctv_N;
int cntdir_by_ccno[] = {4,2,4,4,1};
int dir_N_by_ccno[] = {1,2,2,3,4};
int dir_list_by_ccno[5][4] = {{0},{0,2},{0,1},{0,1,2},{0,1,2,3}};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
inline int Min(int x, int y) {
	return x<y?x:y;
}
int mn = 0x3f3f3f3f;
void go(Coord co, int dir) {
	int nx=co.x, ny=co.y;
	while(true) {
		nx += dx[dir];
		ny += dy[dir];
		if(nx<0 || ny<0 || nx>=n || ny>=m) return;
		if(v[nx][ny]==6) return;
		if(v[nx][ny]<=0) {
			v[nx][ny]--;
		}
	}
}
void ungo(Coord co, int dir) {
	int nx=co.x, ny=co.y;
	while(true) {
		nx += dx[dir];
		ny += dy[dir];
		if(nx<0 || ny<0 || nx>=n || ny>=m) return;
		if(v[nx][ny]==6) return;
		if(v[nx][ny]<0) {
			v[nx][ny]++;
		}
	}
}
void dfs(int th) {
	if(th<0) {
		int cnt=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(v[i][j]==0) cnt++;
			}
		}
		mn = Min(mn, cnt);
		return;
	}

	int ccno = v[cctv_list[th].x][cctv_list[th].y]-1;
	for(int i=0; i<cntdir_by_ccno[ccno]; i++) { //방향의 개수
		for(int j=0; j<dir_N_by_ccno[ccno]; j++) {
			int dir = (dir_list_by_ccno[ccno][j]+i)%4;
			go(cctv_list[th], dir);
		}
		dfs(th-1);
		for(int j=0; j<dir_N_by_ccno[ccno]; j++) {
			int dir = (dir_list_by_ccno[ccno][j]+i)%4;
			ungo(cctv_list[th], dir);
		}
	}
	
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
			if(0<v[i][j] && v[i][j]<6) {
				cctv_list[cctv_N++] = {i,j};
			}
		}
	}

	dfs(cctv_N-1);
	printf("%d\n", mn);
	return 0;
}
