#include <cstdio>
using namespace std;
struct Coord{
	int x,y;
	Coord() {}
	Coord(int x, int y):x(x),y(y) {}
};
Coord co[64];
int v[8][8];


void set_val(int i, int j, int k, int val) {
	v[co[i].x][co[i].y] = val;
	v[co[j].x][co[j].y] = val;
	v[co[k].x][co[k].y] = val;
}

constexpr int MASK = 127;
constexpr int QSZ = MASK+1;
struct Queue{
	Coord q[QSZ];
	int f,r;
	void push(Coord x) {
		q[r++] = x;
		r&=MASK;
	}
	Coord pop() {
		Coord co = q[f++];
		f&=MASK;
		return co;
	}
	int size() const {
		int sz = r-f;
		if(sz<0) sz+=QSZ;
		return sz;
	}
	bool empty() const {
		return r==f;
	}

	Queue():f(0),r(0) {}
	Queue & operator=(Queue & rhs) {
		f = rhs.f;
		r = rhs.r;

		int sz = size();
		for(int i=0; i<sz; i++) {
			int ni = ((f+i)&MASK);
			q[ni] = rhs.q[ni];
		}
		return *this;
	}
};

inline int max(int x, int y) {
	return x>y?x:y;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m,z,mx,wall_cnt;

Queue init_q, q;

int y;
Coord virus[64];
int chk[8][8];
int CHKVAL;
void bfs() {
	q = init_q;
	int sz = q.size();
	CHKVAL++;

	int virus_cnt=0;
	for(int i=0; i<sz; i++) {
		chk[q.q[i].x][q.q[i].y] = CHKVAL;
		virus_cnt++;
	}

	while(!q.empty()) {
		Coord co = q.pop();
		for(int i=0; i<4; i++) {
			int nx=co.x+dx[i], ny=co.y+dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(v[nx][ny]) continue;
			if(chk[nx][ny] == CHKVAL) continue;

			chk[nx][ny] = CHKVAL;
			q.push(Coord(nx,ny));
			virus_cnt++;
		}
	}

    mx = max(mx, n*m - ((wall_cnt+3) + virus_cnt));
}


int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
			co[z++] = Coord(i,j);
			if(v[i][j] == 2) init_q.push(co[z-1]);
			else if(v[i][j] == 1) wall_cnt++;
		}
	}

	for(int i=0; i<z; i++) {
		if(v[co[i].x][co[i].y]) continue;
		for(int j=i+1; j<z; j++) {
			if(v[co[j].x][co[j].y]) continue;
			for(int k=j+1; k<z; k++) {
				if(v[co[k].x][co[k].y]) continue;
				set_val(i,j,k,1);
				bfs();
				set_val(i,j,k,0);
			}
		}
	}
	printf("%d\n", mx);
	return 0;
}
