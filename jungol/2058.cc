#include <stdio.h>
#include <queue>
using namespace std;
struct Info{
	int x[2],y[2];
	Info(){}
	Info(int ax, int ay, int bx, int by){
		x[0]=ax; y[0]=ay; x[1]=bx; y[1]=by;
	}
	Info& operator=(const Info &rhs) {
		this->x[0]=rhs.x[0];
		this->x[1]=rhs.x[1];
		this->y[0]=rhs.y[0];
		this->y[1]=rhs.y[1];
		return *this;
	}
};
queue<Info> q;
int v[25][25];
bool chk[25][25][25][25];
int dx[]={0,-1,-1,0,1,1,1,0,-1},dy[]={0,0,1,1,1,0,-1,-1,-1};
int n;
inline bool isValid(int x,int y) {
	if(x<0||y<0||x>=n||y>=n||v[x][y]) return false;
	else return true;
}
inline int ABS(int x) { return x<0?-x:x; }
inline bool isClose(int ax,int ay,int bx,int by) {
	return (ABS(ax-bx)<=1 && ABS(ay-by)<=1);
}
int main() {
	scanf("%d",&n);
	int sx[2],sy[2],ex[2],ey[2];
	for(int i=0; i<2; i++) {
		scanf("%d%d%d%d",&sx[i],&sy[i],&ex[i],&ey[i]);
		sx[i]--; sy[i]--; ex[i]--; ey[i]--;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d",&v[i][j]);
		}
	}

	int cnt=0;
	bool finA=false,finB=false;
	q.push(Info(sx[0],sy[0],sx[1],sy[1]));
	chk[sx[0]][sy[0]][sx[1]][sy[1]]=true;
	while(!q.empty()) {
		int sz = q.size();
		for(int z=0; z<sz; z++) {
			Info t = q.front(); q.pop();

			if(t.x[0]==ex[0] && t.y[0]==ey[0]) finA=true;
			else finA=false;
			if(t.x[1]==ex[1] && t.y[1]==ey[1]) finB=true;
			else finB=false;
			if(finA && finB) return 0&printf("%d",cnt);
			else {
				for(int i=0; i<9; i++) {
					int nx[2],ny[2];
					nx[0]=t.x[0]+dx[i]; ny[0]=t.y[0]+dy[i];
					if(!isValid(nx[0],ny[0])) continue;
					for(int j=!i; j<9; j++) {
						nx[1]=t.x[1]+dx[j]; ny[1]=t.y[1]+dy[j];
						if(!isValid(nx[1],ny[1])) continue;
						if(chk[nx[0]][ny[0]][nx[1]][ny[1]]) continue;
						if(isClose(nx[0],ny[0],nx[1],ny[1])) continue;
						chk[nx[0]][ny[0]][nx[1]][ny[1]]=true;
						q.push(Info(nx[0],ny[0],nx[1],ny[1]));
					}
				}
			}
		}
		cnt++;
	}
	return 0;
}
