#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
queue<pii> q;
char s[501][501];
int level[501][501];
bool chk[501][501];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,ans=0x3f3f3f3f;
pii b,e;
struct Info{
    int x,y,dist;
    Info(){}
    Info(int x,int y,int dist) :x(x),y(y),dist(dist) {}
    bool operator<(const Info &rhs) const {
        return dist<rhs.dist;
    }
};
priority_queue<Info> mxh;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    memset(level,-1,sizeof(level));
    for(int i=0; i<n; i++) {
        scanf("%s",s[i]);
        for(int j=0; j<m; j++) {
            if(s[i][j]=='+') {
                q.push(pii(i,j));
                level[i][j]=0;
            } else if(s[i][j]=='V') b=pii(i,j);
            else if(s[i][j]=='J') e=pii(i,j);
        }
    }
    s[b.first][b.second]=s[e.first][e.second]='.';
    int cnt=0;
    while(!q.empty()) {
        int sz=q.size();
        for(int z=0; z<sz; z++) {
            pii tmp = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nx=tmp.first+dx[i],ny=tmp.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(level[nx][ny]>=0) continue;
                level[nx][ny]=cnt+1;
                q.push(pii(nx,ny));
            }
        } cnt++;
    }

    mxh.push(Info(b.first,b.second,level[b.first][b.second]));
    chk[b.first][b.second]=true;
    while(!mxh.empty()) {
        Info tmp = mxh.top(); mxh.pop();
        if(tmp.x==e.first && tmp.y==e.second) {
            return 0&printf("%d",tmp.dist);
        }
        for(int i=0; i<4; i++) {
            int nx=tmp.x+dx[i],ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(chk[nx][ny]) continue;
            chk[nx][ny]=true;
            level[nx][ny]=min(level[tmp.x][tmp.y],level[nx][ny]);
            mxh.push(Info(nx,ny,level[nx][ny]));
        }
    }
    return 0;
}
