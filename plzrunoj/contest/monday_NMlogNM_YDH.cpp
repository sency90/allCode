#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> pipii;
priority_queue<pipii, vector<pipii>, greater<pipii> > mnh;
int cost[301][301];
bool chk[301][301];
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={1,1,0,-1,-1,-1,0,1};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==-2) cost[i][j]=0;
        }
    }
    n++; m++;

    cost[0][0]=cost[0][1]=cost[1][0]=-1;
    cost[n][m]=cost[n-1][m]=cost[n][m-1]=-1;

    mnh.push(pipii(0,pii(0,m)));
    int lim = (n+1)*(m+1);
    pipii tmp;
    for(int i=0; i<lim; i++) {
        while(!mnh.empty()) {
            tmp = mnh.top(); mnh.pop();
            if(!chk[tmp.second.first][tmp.second.second]) break;
        }
        int c=tmp.first, x=tmp.second.first, y=tmp.second.second;
        chk[x][y]=true;
        if(x==n && y==0) return 0&printf("%d\n", c);
        for(int i=0; i<8; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0||ny<0||nx>n||ny>m) continue;
            if(chk[nx][ny]) continue;
            if(cost[nx][ny]==-1) continue;
            mnh.push(pipii(c+cost[nx][ny], pii(nx,ny)));
        }
        if(mnh.empty()) break;
    }
    puts("-1");
    return 0;
}
