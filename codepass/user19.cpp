#define MAXN    (50)
#define MAXD    (11)

typedef unsigned long long ull;
struct Cell{
	ull x[2];
	Cell() {x[0]=x[1]=0ULL; }
	Cell(int (*p)[MAXD], int D) {
		x[0]=x[1]=0ULL;
		int bitcnt=0;
		for(int i=0; i<D; i++) {
			for(int j=0; j<D; j++) {
				x[bitcnt/64] <<= 1;
				x[bitcnt/64] |= (p[i][j]-1);
				bitcnt++;
			}
		}
	}
	Cell(int N, int D, int (*map)[MAXN], int sx, int sy) {
		x[0]=x[1]=0ULL;
		int bitcnt=0;
		for(int i=(sx-D/2+N)%N, n=0; n<D; i++, n++) {
			if(i==N) i=0;
			for(int j=(sy-D/2+N)%N, m=0; m<D; j++, m++) {
				if(j==N) j=0;
				x[bitcnt/64] <<= 1;
				x[bitcnt/64] |= (map[i][j]-1);
				bitcnt++;
			}
		}
	}
	inline bool operator==(const Cell & rhs) const {
		return x[0]==rhs.x[0] && x[1]==rhs.x[1];
	}
};

extern int useDetector(int P[MAXD][MAXD]);
struct Result { 
	int r, c; 
	Result(){}
	Result(int r, int c):r(r),c(c) {}
};

Cell fore[MAXN][MAXN];
int chk[MAXN][MAXN][10000];
int CHKVAL;
int N, D, K;
struct Info{
	int x,y,dir,g;
	Info() {}
	Info(int x, int y, int dir, int g):x(x),y(y),dir(dir),g(g) {}
};
template <typename T>
struct Queue{
	const int m = (1<<21)-1;
	T v[1<<21]; //MAXN*MAXN*4*250
	int f,r,sz;
	Queue():f(0),r(0) {}
	void clear() { f=r=sz=0; }
	void push(const T & c) {
		v[r++] = c;
		sz++;
		r &= m;
	}
	T& front() { return v[f]; }
	void pop() {
		f++;
		f &= m;
		sz--;
	}
	bool empty() const { return sz==0; }
	int size() const { return sz; }
};
Queue<Info> q;
//deque<Info> q;
int p[MAXD][MAXD];

void init(int N, int D, int mForest[MAXN][MAXN], int K)
{
	::N=N; ::D=D; ::K=K;
	CHKVAL++;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			fore[i][j] = Cell(N, D, mForest, i, j);
		}
	}

	q.clear();
}

inline void renew(int & c) {
	if(c==N) c=0;
	if(c<0) c+=N;
}

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
Result findCriminal()
{
	q.clear();
	CHKVAL++;

	{
		useDetector(p);
		Cell c(p, D);

		int gcnt=0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(fore[i][j] == c) {
					for(int dir=0; dir<4; dir++) {
						int pi=i+dx[(dir+2)&3], pj=j+dy[(dir+2)&3];
						renew(pi); renew(pj);
						chk[i][j][gcnt] = CHKVAL;
						chk[pi][pj][gcnt] = CHKVAL;
						q.push(Info(i,j,dir,gcnt++));
					}
				}
			}
		}

		if(gcnt==4) return Result(q.front().x, q.front().y);
	}

	int lev = 0;
	while(!q.empty()) {
		int sz = q.size();
		useDetector(p);
		Cell c(p, D);
		for(int z=0; z<sz; z++) {
			Info info = q.front(); q.pop();
			int dir = info.dir;
			for(int i=0; i<4; i++) {
				int nx = info.x + dx[dir];
				int ny = info.y + dy[dir];
				renew(nx); renew(ny);
				if(chk[nx][ny][info.g] == CHKVAL) {
					dir++; dir&=3;
					continue;
				}
				else {
					if(fore[nx][ny] == c) {
						chk[nx][ny][info.g] = CHKVAL;
						q.push(Info(nx,ny,dir,info.g));
						break;
					}
				}
			}
		}
		lev++;

		if(q.size()==1) {
			return Result(q.front().x, q.front().y);
		}
	}

	return Result();
}

