#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
char board[10][11];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

struct Coord{
	int x,y;
	Coord(){}
	Coord(int x, int y):x(x),y(y) {}

	void Move(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
	bool operator==(const Coord & rhs) const {
		return x==rhs.x && y==rhs.y;
	}
};

bool chk[10][10][10][10];
typedef pair<Coord,Coord> pcc;
Coord blue, red, hole;
queue<pcc> q;

bool Simul(Coord r, Coord b, int dx, int dy, int &rdist, int &bdist) {
	bool rmove = false, bmove = false, rover=false, bover=false;
	for(int i=0; i<100; i++) {
		char bb = board[b.x+dx][b.y+dy];
		if(!bover) {
			if(bb == '.') b.Move(dx,dy), bdist++, bmove=true, bover=false;
			else if(bb == 'O') return false;
			else bmove=false, bover=true;
		}

		char rb = board[r.x+dx][r.y+dy];
		if(!rover) {
			if(rb == '.') r.Move(dx,dy), rdist++, rmove=true, rover=false;
			else if(rb == 'O') r.Move(dx,dy), rdist++, rmove=true, rover=true;
			else rmove=false, rover=true;
		}

		if(b == r) {
			if(bmove) bdist--;
			if(rmove) rdist--;
			break;
		}

		if(rover && bover) {
			break;
		}
	}
	return (bdist>0 || rdist>0);
}

bool Go(Coord & r, Coord & b, int dx, int dy, int rdist, int bdist) {
	r.Move(dx*rdist, dy*rdist);
	b.Move(dx*bdist, dy*bdist);
	return r==hole;
}


int main() {
	int n, m; scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%s", board[i]);
		for(int j=0; j<m; j++) {
			if(board[i][j] == 'B') {
				board[i][j] = '.';
				blue = {i,j};
			}
			else if(board[i][j] == 'R') {
				board[i][j] = '.';
				red = {i,j};
			}
			else if(board[i][j] == 'O') {
				hole = {i,j};
			}
		}
	}

	chk[red.x][red.y][blue.x][blue.y] = true;
	q.push(pcc(red, blue));
	int ans = 1;
	while(!q.empty()) {
		int sz = q.size();
		for(int z=0; z<sz; z++) {
			pcc pco = q.front(); q.pop();
			for(int i=0; i<4; i++) {
				Coord r = pco.first, b = pco.second;
				int rdist=0, bdist=0;
				if(!Simul(r, b, dx[i], dy[i], rdist, bdist)) continue;
				if(chk[r.x+dx[i]*rdist][r.y+dy[i]*rdist][b.x+dx[i]*bdist][b.y+dy[i]*bdist]) continue;
				if(Go(r, b, dx[i], dy[i], rdist, bdist)) {
					printf("%d\n", ans);
					return 0;
				}
				else {
					chk[r.x][r.y][b.x][b.y] = true;
					q.push(pcc(r,b));
				}
			}
		}
		if(++ans>10) break;
	}
	puts("-1");
	return 0;
}
