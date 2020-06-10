#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct Info{
    int x, y, b;
    Info(){}
    Info(int x, int y, int b):x(x),y(y),b(b) {}
};
queue<Info> q;
char str[1002][1002];
bool chk[1002][1002][2];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n, m; scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
    }
    int ans=1;
    chk[0][0][0] = true;
    q.emplace(0,0,0);
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            Info r = q.front(); q.pop();
            if(r.x==n-1 && r.y==m-1) {
                return 0&printf("%d\n", ans);
            }
            for(int i=0; i<4; i++) {
                int nx=r.x+dx[i], ny=r.y+dy[i], nb=r.b;
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(str[nx][ny]=='1') {
                    if(nb==0) nb++;
                    else continue;
                }
                if(chk[nx][ny][nb]) continue;
                else {
                    chk[nx][ny][nb] = true;
                    q.emplace(nx,ny,nb);
                }
            }
        }
        ans++;
    }
    puts("-1");
    return 0;
}

