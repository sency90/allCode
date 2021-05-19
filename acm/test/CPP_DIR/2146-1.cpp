//group number와 level을 기록하는 배열 g[][]를 만들어서 해결하였다.
//처음에 bfs탐색을 하면서 그룹별로 그룹 번호를 매긴다음에
//다시 한번 bfs탐색을 하면서 그룹번호가 틀린 것 끼리 만나면
//서로의 level값을 더해주고 그것의 최소값을 기록하였다.
#include <stdio.h>
#include <queue>
using namespace std;
int v[100][100];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
queue<pair<int,int> > q, tmpQ;
pair<int,int> g[100][100];
bool chk[100][100];
struct Info{
    int l, x, y;
    Info(int ll, int xx, int yy) {
        l=ll; x=xx; y=yy;
    }
    bool operator<(const Info& rhs) const {
        return l > rhs.l;
    }
};
priority_queue<Info> mnh;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
            if(v[i][j]==1) tmpQ.push(make_pair(i,j));
        }
    }
    pair<int,int> t;
    int gn=0, nx, ny;
    while(!tmpQ.empty()) {
        t = tmpQ.front(); tmpQ.pop();
        if(chk[t.first][t.second]) continue;
        chk[t.first][t.second] = true;
        g[t.first][t.second] = make_pair(++gn,0);
        q.push(t);
        mnh.push(Info(0,t.first,t.second));
        while(!q.empty()) {
            t = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                nx = t.first + dx[i];
                ny = t.second + dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(v[nx][ny]==0) continue;
                if(chk[nx][ny]) continue;
                chk[nx][ny] = true;
                g[nx][ny] = make_pair(gn,0);
                q.push(make_pair(nx,ny));
                mnh.push(Info(0,nx,ny));
            }
        }
    }

    Info th(0,0,0);
    int mn = 0x3f3f3f3f;
    while(!mnh.empty()) {
        th = mnh.top(); mnh.pop();
        for(int i=0; i<4; i++) {
            nx = th.x + dx[i];
            ny = th.y + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(chk[nx][ny]) {
                if(g[nx][ny].first!=0 && g[nx][ny].first!=g[th.x][th.y].first) {
                    if(mn > g[nx][ny].second+th.l) {
                        mn = g[nx][ny].second+th.l;
                    }
                }
                continue;
            }
            chk[nx][ny] = true;
            g[nx][ny] = make_pair(g[th.x][th.y].first, th.l+1);
            mnh.push(Info(th.l+1,nx,ny));
        }
    }
    printf("%d", mn);
    return 0;
}
