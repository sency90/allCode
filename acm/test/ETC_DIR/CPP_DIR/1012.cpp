#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
queue<pair<int,int> > q;
bool chk[50][50], v[50][50];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, m, k;
void bfs(int x, int y) {
    chk[x][y] = true;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        int nx, ny;
        for(int i=0; i<4; i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(chk[nx][ny]) continue;
            if(!v[nx][ny]) continue;
            chk[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}
int main() {
    int t, x, y, cnt;
    scanf("%d", &t);
    while(t--) {
        cnt=0;
        memset(v, false, sizeof(v));
        memset(chk, false, sizeof(chk));
        scanf("%d %d %d", &m, &n, &k);
        for(int i=0; i<k; i++) {
            scanf("%d %d", &y, &x);
            v[x][y] = true;
        }
        for(int i=0; i<50; i++) {
            for(int j=0; j<50; j++) {
                if(chk[i][j]) continue;
                if(!v[i][j]) continue;
                cnt++;
                bfs(i, j);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
