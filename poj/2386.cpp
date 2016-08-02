#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
char board[100][101];
bool chk[100][101];
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={1,1,0,-1,-1,-1,0,1};
int n, m;
void dfs(int x, int y) {
    chk[x][y] = true;
    for(int i=0; i<8; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        if(chk[nx][ny]) continue;
        chk[nx][ny] = true;

        if(board[nx][ny]=='W') dfs(nx,ny);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", board[i]);
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(chk[i][j]) continue;
            if(board[i][j]=='W') {
                cnt++;
                dfs(i,j);
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
