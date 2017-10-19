#include <stdio.h>
#include <queue>
using namespace std;
inline int MAX(int x,int y) { return x>y?x:y; }
inline int MIN(int x,int y) { return x<y?x:y; }
int v[101][101];
struct Info{
	int x,y,dir;
	Info(){}
	Info(int x,int y,int dir):x(x),y(y),dir(dir){}
};
bool chk[101][101][4];
queue<Info> q;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int nexr[]={2,3,1,0},nexl[]={3,2,0,1};
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d",&v[i][j]);
		}
	}
	int sx,sy,sdir,ex,ey,edir;
	scanf("%d%d%d%d%d%d",&sx,&sy,&sdir,&ex,&ey,&edir);
	sx--; sy--; sdir--; ex--; ey--; edir--;
	q.push(Info(sx,sy,sdir));
	chk[sx][sy][sdir]=true;
	int cnt=0;
	while(!q.empty()) {
		int sz = q.size();
		for(int z=0; z<sz; z++) {
			Info t = q.front(); q.pop();
			int x=t.x,y=t.y,dir=t.dir;
			if(x==ex && y==ey && dir==edir) return 0&printf("%d\n",cnt);

			//직진
			int lim = MIN(MAX(n,m),4);
			for(int i=1; i<lim; i++) {
				int nx=x+i*dx[dir],ny=y+i*dy[dir];
				if(nx<0||ny<0||nx>=n||ny>=m) break;
				if(v[nx][ny]) break;
				if(chk[nx][ny][dir]) continue;
				chk[nx][ny][dir]=true;
				q.push(Info(nx,ny,dir));
			}

			//회전
			if(!chk[x][y][nexr[dir]]) {
				chk[x][y][nexr[dir]]=true;
				q.push(Info(x,y,nexr[dir]));
			}
			if(!chk[x][y][nexl[dir]]) {
				chk[x][y][nexl[dir]]=true;
				q.push(Info(x,y,nexl[dir]));
			}
		}
		cnt++;
	}
	return 0;
}
