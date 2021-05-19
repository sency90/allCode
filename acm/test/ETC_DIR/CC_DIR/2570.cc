#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int dx[]={1,1,-1,-1}, dy[]={1,-1,-1,1};
bool block[101][101];
void check(int x, int y) {
    if(block[x][y]) return 0;
    int cnt=0;
    for(int j=0; j<4; j++) {
        for(int k=1;;k++) {
            int nx=x+k*dx[j], ny=y+k*dy[j];
            if(nx<=0||ny<=0||nx>n||ny>n||block[nx][ny]) break;
            block[nx][ny]=true;
        }
    }
    v[src].push_back()
}
int main() {
    scanf("%d%d", &n,&m);
    memset(block, true, sizeof(block));
    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        block[x][y]=true;
    }
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(block[i][j]) {
                check(i,j);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(block[i][j]) cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
