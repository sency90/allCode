#include <cstdio>
using namespace std;
int v[51][51];
inline int abs(int x) {
	return x<0?-x:x;
}
struct Coord{
	int x,y;
	int operator-(const Coord & rhs) const {
		return abs(x-rhs.x) + abs(y-rhs.y);
	}
};
Coord ch_list[15]; //chicken house list
int ch_N;

Coord h_list[101];
int h_N;

Coord ans_list[15];
int ans_N;
constexpr int INF = 0x3f3f3f3f;
constexpr int NA = -1;
int mn_sum = INF;

inline int min(int x, int y) {
	return x<y?x:y;
}
void dfs(int th, int x) {
	if(th==0) {
		ans_list[ans_N++] = ch_list[x];
		int sum=0;
		for(int i=0; i<h_N; i++) {
			int mn_dist = INF;
			for(int j=0; j<ans_N; j++) {
				int dist = h_list[i] - ans_list[j];
				mn_dist = min(mn_dist, dist);
			}
			sum+=mn_dist;
		}
		mn_sum = min(mn_sum, sum);
		ans_N--;
		return;
	}
	else if(th>x) return;
	ans_list[ans_N++] = ch_list[x];
	for(int i=x-1; i>=0; i--) {
		dfs(th-1, i);
	}
	ans_N--;
}
int main() {
	int n,m; scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &v[i][j]);
			if(v[i][j]==1) h_list[h_N++] = {i,j};
			else if(v[i][j]==2) ch_list[ch_N++] = {i,j};
		}
	}

	for(int i=ch_N-1; i>=m-1; i--) {
		dfs(m-1,i);
	}
	printf("%d\n", mn_sum);
	return 0;
}
