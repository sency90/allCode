#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int n,ans;
bool visited[15][15];
int dx[]={0,1,1,1}, dy[]={1,1,0,-1};
inline void block(int x, int y, vector<pii> &chk) {
    visited[x][y]=true;
    chk.push_back(pii(x,y));
    for(int dir=0; dir<4; dir++) {
        for(int i=1; i<n; i++) {
            int nx=x+i*dx[dir], ny=y+i*dy[dir];
            if(nx<0||ny<0||nx>n||ny>n) break;
            if(visited[nx][ny]) continue;
            visited[nx][ny]=true;
            chk.push_back(pii(nx,ny));
        }
    }
}
inline void unblock(vector<pii> &chk) {
    for(int i=0; i<chk.size(); i++) {
        int x=chk[i].first, y=chk[i].second;
        visited[x][y]=false;
    }
}
void dfs(int x, int y, int cnt) {
    if(x==n) return;
    if(cnt==n) {
        ans++;
        return;
    }
    vector<pii> chk;
    block(x,y,chk);
    for(int j=0; j<n; j++) {
        if(visited[x+1][j]) continue;
        dfs(x+1,j,cnt+1);
    }
    unblock(chk);
}
int main() {
    scanf("%d", &n);
    for(int j=0; j<n; j++) dfs(0,j,1);
    printf("%d", ans);
    return 0;
}
