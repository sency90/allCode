#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
int n,h;
int v[101][101], dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool chk[101][101], rchk[101][101];
void bfs(int x, int y) {
    queue<pii> q;
    chk[x][y]=true;
    q.push({x,y});
    while(!q.empty()) {
        int sz=q.size();
        for(int z=0; z<sz; z++) {
            x=q.front().first; y=q.front().second; q.pop();
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(chk[nx][ny]) continue;
                if(v[nx][ny]>=h) continue;
                chk[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}
void dfs(int x, int y) {
    rchk[x][y]=true;
    for(int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n) continue;
        if(chk[nx][ny]) continue;
        if(rchk[nx][ny]) continue;
        dfs(nx,ny);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    int mx=1;
    for(int z=0; z<=100; z++) {
        memset(chk,false,sizeof(chk));
        memset(rchk,false,sizeof(rchk));
        h=z;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(chk[i][j]) continue;
                if(v[i][j]>=h) continue;
                bfs(i,j);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(rchk[i][j]) continue;
                if(!chk[i][j]) {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        mx=max(ans,mx);
    }
    printf("%d\n", mx);
    return 0;
}
