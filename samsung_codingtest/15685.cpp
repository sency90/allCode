#include <cstdio>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
struct Coord{
	int x, y;
};
Coord co_list_by_dgno[21][1026];
int co_N_by_dgno[21];
void rotate90(int dgno, int x, int y, int th, int g) {
	if(th>g) return;
	int lim = co_N_by_dgno[dgno];
	for(int i=lim-2; i>=0; i--) {
		const Coord & co = co_list_by_dgno[dgno][i];
		int nx = x+(co.y-y);
		int ny = y-(co.x-x);
		if(nx<0||ny<0||nx>100||ny>100) continue;
		co_list_by_dgno[dgno][co_N_by_dgno[dgno]++] = {nx,ny};
	}
	const Coord & lco = co_list_by_dgno[dgno][co_N_by_dgno[dgno]-1];
	rotate90(dgno, lco.x, lco.y, th+1, g);
}
bool chk[101][101];
int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int x,y,d,g;
		scanf("%d%d%d%d",&y,&x,&d,&g);
		co_list_by_dgno[i][co_N_by_dgno[i]++] = {x,y};
		int nx=x+dx[d], ny=y+dy[d];
		co_list_by_dgno[i][co_N_by_dgno[i]++] = {nx,ny};
		rotate90(i,nx,ny,1,g);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<co_N_by_dgno[i]; j++) {
			Coord & co = co_list_by_dgno[i][j];
			chk[co.x][co.y] = true;
		}
	}

	int ans=0;
	for(int i=0; i<100; i++) {
		for(int j=0; j<100; j++) {
			if(chk[i][j]) {
				if(chk[i][j+1] && chk[i+1][j] && chk[i+1][j+1]) ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
