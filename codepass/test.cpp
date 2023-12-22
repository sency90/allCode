#include <stdio.h>
#define MAXD 11
#define MAXN 50
typedef unsigned long long ull;
struct Cell{
	ull x[2];
	int bitcnt=0;
	Cell() {x[0]=x[1]=0ULL;}
	Cell(int (*p)[MAXD], int D) {
		x[0]=x[1]=0ULL;
		for(int i=0; i<D; i++) {
			for(int j=0; j<D; j++) {
				x[bitcnt>>6] <<= 1;
				x[bitcnt>>6] |= (p[i][j]-1);
				bitcnt++;
			}
		}
	}
	Cell(int N, int D, int (*map)[MAXN], int sx, int sy) {
		for(int i=sx, n=0; n<D; i++, n++) {
			if(i==N) i=0;
			for(int j=sy, m=0; m<D; j++, m++) {
				if(j==N) j=0;
				x[bitcnt>>6] <<= 1;
				x[bitcnt>>6] |= (map[i][j]-1);
				bitcnt++;
			}
		}
	}
	inline bool operator==(const Cell & rhs) const {
		return x[0]==rhs.x[0] && x[1]==rhs.x[1];
	}
	inline bool operator!=(const Cell & rhs) const {
		return !(*this == rhs);
	}
	inline bool operator<(const Cell & rhs) const {
		if(x[0] == rhs.x[0]) return x[1]<rhs.x[1];
		else return x[0] < rhs.x[0];
	}
	inline bool operator>(const Cell & rhs) const {
		if(x[0] == rhs.x[0]) return x[1]>rhs.x[1];
		else return x[0] > rhs.x[0];
	}
};
int main() {
	return 0;
}
