#include <cstdio>
using namespace std;
int v[20][20];
struct Coord{
	int x,y;
	Coord(){}
	Coord(int x, int y):x(x),y(y) {}
};
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct Dice{
	Coord co;
	int val[6];
	bool roll(int dir, int n, int m) {
		int nx = co.x + dx[dir-1];
		int ny = co.y + dy[dir-1];
		if(nx<0 || ny<0 || nx>=n || ny>=m) return false;

		co.x = nx;
		co.y = ny;

		if(dir==1) swap(0,3,5,2);
		else if(dir == 2) swap(0,2,5,3);
		else if(dir == 3) swap(0,4,5,1);
		else swap(0,1,5,4);

		if(v[nx][ny] == 0) {
			v[nx][ny] = val[5];
		}
		else {
			val[5] = v[nx][ny];
			v[nx][ny] = 0;
		}
		return true;
	}
	void swap(int a, int b, int c, int d) {
		int tmp = val[a];
		val[a] = val[b];
		val[b] = val[c];
		val[c] = val[d];
		val[d] = tmp;
	}
};
Dice dice;
int main() {
	int n,m,k;
	scanf("%d%d%d%d%d",&n,&m,&dice.co.x,&dice.co.y,&k);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	for(int i=0; i<k; i++) {
		int dir; scanf("%d", &dir);
		if(dice.roll(dir,n,m)) {
			printf("%d\n", dice.val[0]);
		}
	}
	return 0;
}
