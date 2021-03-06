#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, pii> plpii;
priority_queue<plpii, vector<plpii>, greater<plpii> > mnh;
ll cost[310][310];
bool chk[310][310];
int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={1,1,0,-1,-1,-1,0,1};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%lld",&cost[i][j]);
            if(cost[i][j]==-2LL) cost[i][j]=0LL;
        }
    }
    n++; m++;

    cost[0][0]=cost[0][1]=cost[1][0]=-1LL;
    cost[n][m]=cost[n-1][m]=cost[n][m-1]=-1LL;

    mnh.push(plpii(0LL,pii(0,m)));
    int lim = (n+1)*(m+1);
    plpii tmp;
    for(int i=0; i<lim; i++) {
        while(!mnh.empty()) {
            tmp = mnh.top(); mnh.pop();
            if(!chk[tmp.second.first][tmp.second.second]) break;
        }
        ll c=tmp.first, x=tmp.second.first, y=tmp.second.second;
        chk[x][y]=true;
        if(x==n && y==0) return 0&printf("%lld\n", c);
        for(int i=0; i<8; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0||ny<0||nx>n||ny>m) continue;
            if(chk[nx][ny]) continue;
            if(cost[nx][ny]==-1LL) continue;
            mnh.push(plpii(c+cost[nx][ny], pii(nx,ny)));
        }
        if(mnh.empty()) break;
    }
    puts("-1");
    return 0;
}
