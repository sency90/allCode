#include <cstdio>
#include <queue>
using namespace std;
int v[101][101],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool chk[101][101];
queue<pair<int,int> > q;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    int ans=1;
    chk[0][0]=true;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int sz=q.size();
        for(int z=0; z<sz; z++) {
            int x=q.front().first, y=q.front().second; q.pop();
            if(x==n-1&&y==m-1) {
                printf("%d", ans);
                return 0;
            }
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(chk[nx][ny] || !v[nx][ny]) continue;
                chk[nx][ny]=true;
                q.push(make_pair(nx,ny));
            }
        }
        ans++;
    }
    return 0;
}
