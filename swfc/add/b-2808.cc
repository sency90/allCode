#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
int n,m;
char s[701][701],chk[701][701];
int lv[701][701],tm[701][701];
pii na,viking,treasure;
queue<pii> q;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
const int inf = 0x3f3f3f3f;
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s",s[i]);
        for(int j=0; j<m; j++) {
            if(s[i][j]=='Y') na=make_pair(i,j);
            else if(s[i][j]=='V') viking=make_pair(i,j);
            else if(s[i][j]=='T') treasure=make_pair(i,j);
        }
    }
    s[na.first][na.second]=s[viking.first][viking.second]=s[treasure.first][treasure.second]='.';
    q.push(viking);
    chk[viking.first][viking.second]=true;


    memset(lv,-1,sizeof(lv));
    int level=0;
    lv[viking.first][viking.second]=level++;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pii tmp = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nx=tmp.first+dx[i],ny=tmp.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(lv[nx][ny]>=0) continue;
                if(s[nx][ny]=='.') {
                    lv[nx][ny]=level;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        level++;
    }

    memset(tm,0x3f,sizeof(tm));
    for(int i=0; i<n; i++) {
        int mn=inf;
        for(int j=0; j<m; j++) {
            mn = min(mn,lv[i][j]);
            if(lv[i][j]<0) {
                mn=inf;
                tm[i][j]=-1;
            } else tm[i][j]=mn;
        }

        mn=inf;
        for(int j=m-1; j>=0; j--) {
            mn = min(mn,lv[i][j]);
            if(lv[i][j]<0) mn=inf;
            else tm[i][j]=min(mn,tm[i][j]);
        }
    }

    for(int j=0; j<m; j++) {
        int mn=inf;
        for(int i=0; i<n; i++) {
            mn=min(mn,lv[i][j]);
            if(lv[i][j]<0) mn=inf;
            else tm[i][j]=min(mn,tm[i][j]);
        }

        mn=inf;
        for(int i=n-1; i>=0; i--) {
            mn=min(mn,lv[i][j]);
            if(lv[i][j]<0) mn=inf;
            else tm[i][j]=min(mn,tm[i][j]);
        }
    }

    memset(chk,false,sizeof(chk));
    q.push(na);
    chk[na.first][na.second]=true;
    level=1;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pii tmp = q.front(); q.pop();
            if(tmp.first==treasure.first && tmp.second==treasure.second) return 0&puts("YES");
            for(int i=0; i<4; i++) {
                int nx=tmp.first+dx[i],ny=tmp.second+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(tm[nx][ny]<=level) continue;
                //if(chk[nx][ny]) continue;
                //chk[nx][ny]=true;
                if(s[nx][ny]=='.') {
                    if(chk[nx][ny]) continue;
                    chk[nx][ny]=true;
                    q.push(pii(nx,ny));
                }
            }
        }
        level++;
    }
    puts("NO");
    return 0;
}
