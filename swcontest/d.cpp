#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int m,n,sx,sy,ex,ey;
char s[41][41];
bool chk[41][41][4];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int rdfs_ans, ldfs_ans;
bool hasAns;
void rdfs(int x, int y, int dir) {
	if(hasAns) return;
	chk[x][y][dir] = true;
	rdfs_ans++;
	if(x==ex && y==ey) {
		hasAns = true;
		return;
	}
	for(int i=0; i<4; i++) {
		int ndir=dir-i+1;
		if(ndir<0) ndir+=4;
		else if(ndir==4) ndir=0;
		int nx=x+dx[ndir], ny=y+dy[ndir];
		if(nx<0 || ny<0 || nx>=n | ny>=m) continue;
		if(chk[nx][ny][ndir]) continue;
		if(s[nx][ny]=='#') continue;
		rdfs(nx,ny,ndir);
		if(hasAns) break;
	}
}
void ldfs(int x, int y, int dir) {
	if(hasAns) return;
	chk[x][y][dir] = true;
	ldfs_ans++;
	if(x==ex && y==ey) {
		hasAns = true;
		return;
	}
	for(int i=0; i<4; i++) {
		int ndir=(dir+i+3)%4;
		int nx=x+dx[ndir], ny=y+dy[ndir];
		if(nx<0 || ny<0 || nx>=n | ny>=m) continue;
		if(chk[nx][ny][ndir]) continue;
		if(s[nx][ny]=='#') continue;
		ldfs(nx,ny,ndir);
		if(hasAns) break;
	}

}

struct Info {
	int x, y;
	Info() {}
	Info(int x, int y):x(x),y(y) {}
	bool operator==(const Info & rhs) const {
		return x==rhs.x && y==rhs.y;
	}
};
bool visit[41][41];
queue<Info> q;
int main() {
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++) {
		scanf("%s", s[i]);
		for(int j=0; j<m; j++) {
			if(s[i][j]=='S') { sx = i; sy = j; }
			else if(s[i][j]=='E') { ex = i; ey = j; }
		}
	}

	memset(chk,false,sizeof(chk));
	hasAns = false;
	int dir;
	if(sx == 0) dir = 2;
	else if(sx == n-1) dir = 0;
	else if(sy == 0) dir = 1;
	else dir = 3;
	ldfs(sx,sy,dir);

	memset(chk,false,sizeof(chk));
	hasAns = false;
	rdfs(sx,sy,dir);

	hasAns = false;
	int mindist = 1;
	visit[sx][sy] = true;
	q.emplace(sx,sy);
	while(!q.empty()) {
		int sz = q.size();
		for(int z=0; z<sz; z++) {
			Info info = q.front(); q.pop();
			if(info.x == ex && info.y == ey) {
				hasAns = true;
				break;
			}
			for(int i=0; i<4; i++) {
				int nx = info.x + dx[i];
				int ny = info.y + dy[i];
				if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
				if(s[nx][ny] == '#') continue;
				if(visit[nx][ny]) continue;
				visit[nx][ny] = true;
				q.emplace(nx,ny);
			}
		}
		if(hasAns) break;
		mindist++;
	}
	printf("%d %d %d\n",ldfs_ans, rdfs_ans, mindist);
	return 0;
}
