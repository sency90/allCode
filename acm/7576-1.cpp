#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int mp[1000][1000], dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
queue<pair<int,int> > q;
int main() {
    int n, m, d;
    scanf("%d%d",&m,&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &d);
            if(d==1) q.push(make_pair(i,j));
            mp[i][j] = d;
        }
    }
    int nx, ny, x, y, mx=1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(mp[nx][ny]!=0) continue;
            mp[nx][ny] = mp[x][y]+1;
            if(mx < mp[nx][ny]) mx = mp[nx][ny];
            q.push(make_pair(nx,ny));
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[i][j]==0) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d", mx-1);
    return 0;
}
