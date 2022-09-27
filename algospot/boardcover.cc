#include <cstdio>
#include <cstring>
using namespace std;
char s[21][21];
bool chk[21][21];
int n,m;
struct Coord{
	int x,y;
	Coord() {}
	Coord(int x, int y):x(x),y(y) {}
	bool operator<(const Coord & rhs) const {
		if(x==rhs.x) return y<rhs.y;
		else return x<rhs.x;
	}
};

Coord blk[4][3] = {
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool fill(int k, int x, int y) {
	bool canFill = true;
	for(int i=0; i<3; i++) {
		int nx = x+blk[k][i].x, ny = y+blk[k][i].y;
		if(nx<0 || ny<0 || nx>=n || ny>=m) return false;
		if(chk[nx][ny] || s[nx][ny]=='#') return false;
	}

	if(canFill) {
		for(int i=0; i<3; i++) {
			int nx=x+blk[k][i].x, ny=y+blk[k][i].y;
			chk[nx][ny] = true;
		}
	}
	return canFill;
}
void unfill(int k, int x, int y) {
	for(int i=0; i<3; i++) {
		int nx=x+blk[k][i].x, ny=y+blk[k][i].y;
		chk[nx][ny] = false;
	}
}

int cnt, anscnt, ans;
void dfs(int x, int y) {
	if(x==n && y==0) {
		if(cnt == anscnt) ans++;
		return;
	}
	for(int k=0; k<4; k++) {
		if(fill(k,x,y)) {
			cnt+=3;
			if(y+1==m) dfs(x+1,0);
			else dfs(x,y+1);
			unfill(k,x,y);
			cnt-=3;
		}
	}
	if(s[x][y]=='#' || chk[x][y]) {
		if(y+1==m) dfs(x+1,0);
		else dfs(x,y+1);
	}
}
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d",&n,&m);
		cnt=anscnt=ans=0;
		for(int i=0; i<n; i++) {
			scanf("%s", s[i]);
			for(int j=0; j<m; j++) {
				if(s[i][j]=='.') anscnt++;
			}
		}

		memset(chk,false,sizeof(chk));
		dfs(0,0);
		printf("%d\n", ans);
	}
	return 0;
}
