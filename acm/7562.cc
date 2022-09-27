#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int chk[301][301];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
struct Info{
	int x,y;
	Info() {}
	Info(int x, int y):x(x),y(y) {}
};
deque<Info> q;
int main() {
	int tc; scanf("%d", &tc);
	for(int t=1; t<=tc; t++) {
		q.clear();
		int n,sx,sy,ex,ey;
		scanf("%d%d%d%d%d", &n,&sx,&sy,&ex,&ey);
		int cnt = 0;

		chk[sx][sy] = t;
		q.emplace_back(sx,sy);
		while(!q.empty()) {
			int sz = q.size();
			for(int z=0; z<sz; z++) {
				Info info = q.front(); q.pop_front();
				if(info.x == ex && info.y == ey) {
					printf("%d\n", cnt);
					goto END_BFS;
				}
				for(int i=0; i<8; i++) {
					int nx = info.x + dx[i];
					int ny = info.y + dy[i];
					if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
					if(chk[nx][ny] == t) continue;
					chk[nx][ny] = t;
					q.emplace_back(nx,ny);
				}
			}
			cnt++;
		}
END_BFS:;
	}
	return 0;
}
