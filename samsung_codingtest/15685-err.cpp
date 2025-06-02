#include <cstdio>
#include <cstdlib>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
struct Coord{
	int x, y;
	bool operator<(const Coord & rhs) const {
		if(x==rhs.x) return y<rhs.y;
		else return x<rhs.x;
	}
	void print() const {
		printf("(%d,%d)", x,y);
	}
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
void Swap(Coord & lco, Coord & rco) {
	Coord tmp = lco;
	lco = rco;
	rco = tmp;
}
bool chk[101][101];
int lno_N=0;
int lno[101][101];
int line_list_by_lno[10001][2];
int line_N_by_lno[10001];
Coord co_by_lno[10001];
void Assert(bool cond, const int line_no) {
	if(!cond) {
		printf("ASSERT_FAIL @ Line%d\n", line_no);
		exit(1);
	}
}
int getDir(int x, int y) {
	for(int i=0; i<4; i++) {
		if(dx[i]==x && dy[i]==y) return i;
	}
	Assert(false, __LINE__);
	return -1;
}
int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int x,y,d,g;
		scanf("%d%d%d%d",&y,&x,&d,&g);
		co_list_by_dgno[i][co_N_by_dgno[i]++] = {x,y};
		int nx=x+dx[d], ny=y+dy[d];
		co_list_by_dgno[i][co_N_by_dgno[i]++] = {nx,ny};
		rotate90(i,nx,ny,1,g);
		printf("dgno:%d -> ", i);
		for(int j=0; j<co_N_by_dgno[i]; j++) {
			const Coord & co = co_list_by_dgno[i][j];
			printf("(%d,%d) ", co.x, co.y);
		}
		puts("");
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<co_N_by_dgno[i]-1; j++) {
			Coord co1 = co_list_by_dgno[i][j];
			Coord co2 = co_list_by_dgno[i][j+1];
			if(co2 < co1) Swap(co1, co2);
			if(lno[co1.x][co1.y]==0) {
				lno[co1.x][co1.y] = ++lno_N;
				co_by_lno[lno_N] = co1;
			}
			int dir = getDir(co2.x-co1.x, co2.y-co1.y);
			//if(dir>1) {
			//	printf("co1: "); co1.print(); puts("");
			//	printf("co2: "); co2.print(); puts("");
			//	printf("dir:%d\n", dir);
			//}
			Assert(dir==0 || dir==3, __LINE__);
			line_list_by_lno[lno[co1.x][co1.y]][line_N_by_lno[lno[co1.x][co1.y]]++] = dir;
		}
	}

	int ans=0;
	for(int i=1; i<=lno_N; i++) {
		Coord sco = co_by_lno[i];
		if(line_N_by_lno[i]<2) continue;
		int cnt=0;
		for(int j=0; j<line_N_by_lno[i]; j++) {
			int dir = line_list_by_lno[i][j];
			int nx = sco.x + dx[dir];
			int ny = sco.y + dy[dir];

			if(lno[nx][ny] == 0) break;
			int l = lno[nx][ny];
			for(int k=0; k<line_N_by_lno[l]; k++) {
				int ndir = line_list_by_lno[l][k];
				if((dir + ndir) == 3) {
					cnt++;
					break;
				}
			}
		}
		if(cnt == 2) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
