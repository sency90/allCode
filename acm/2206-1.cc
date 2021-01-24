#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
bool chk[1002][1002][2];
int v[1002][1002];
struct Info{
	int x,y,s;
	Info(){}
	Info(int x, int y, int s):x(x),y(y),s(s) {}
};
queue<Info> q;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%1d", &v[i][j]);
		}
	}

	int cnt=0;
	chk[0][0][0] = true;
	q.emplace(0,0,0);
	while(!q.empty()) {
		int sz = q.size();
		for(int z=0; z<sz; z++) {
			Info info = q.front(); q.pop();
			if(info.x==n-1 && info.y==m-1) {
				return 0&printf("%d", cnt+1);
			}
			for(int i=0; i<4; i++) {
				int nx = info.x + dx[i];
				int ny = info.y + dy[i];
				int ns = info.s;
				if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

				if(v[nx][ny]==1) {
					if(info.s==0) ns++;
					else continue;
				}
				if(chk[nx][ny][ns]) continue;
				chk[nx][ny][ns] = true;
				q.emplace(nx,ny,ns);
			}
		}
		cnt++;
	}
	puts("-1");
	return 0;
}
