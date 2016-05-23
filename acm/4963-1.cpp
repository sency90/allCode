#include <stdio.h>
#include <queue>
using namespace std;
pair<int,int> tmp;
int v[51][51];
int dx[]={1,-1,0,0,1,1,-1,-1}, dy[]={0,0,1,-1,1,-1,-1,1};
int main() {
    int w, h, nx, ny, cnt;
    while(true) {
        queue<pair<int,int> > q, totalQ;
        cnt=0;
        scanf("%d%d",&w,&h);
        if(w==0 && h==0) return 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                scanf("%d", &v[i][j]);
                if(v[i][j]==1) totalQ.push(make_pair(i,j));
            }
        }
        while(!totalQ.empty()) {
            tmp = totalQ.front(); totalQ.pop();
            if(v[tmp.first][tmp.second]==0) continue;
            cnt++;
            v[tmp.first][tmp.second]=0;
            q.push(tmp);
            while(!q.empty()) {
                tmp = q.front(); q.pop();
                for(int i=0; i<8; i++) {
                    nx = tmp.first + dx[i];
                    ny = tmp.second + dy[i];
                    if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
                    if(v[nx][ny]==0) continue;
                    v[nx][ny] = 0;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        printf("%d\n", cnt);
    }
}
