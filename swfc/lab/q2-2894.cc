#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int v[40][40], d[15][1<<15], pos[40][40], dist[42][42];
pii s,e;
int snum=1;
vector<pii> student(1,pii(0,0));
queue<pii> q;
bool chk[40][40];
int cnt(int bit) {
    int cnt=0;
    while(bit) {
        if(bit&1) cnt++;
        bit>>=1;
    }
    return cnt;
}
int main() {
    //freopen("input.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&v[i][j]);
            if(v[i][j]==2) s=pii(i,j);
            else if(v[i][j]==4) e=pii(i,j);
            else if(v[i][j]==3) {
                pos[i][j]=snum++;
                student.push_back(pii(i,j));
            }

        }
    }
    pos[s.first][s.second]=0;
    pos[e.first][e.second]=snum++;
    student[0]=s;
    student.push_back(e);

    memset(dist,0x3f,sizeof(dist));
    dist[0][0]=0;
    for(int z=0; z<snum; z++) {
        memset(chk,false,sizeof(chk));
        int xx=student[z].first,yy=student[z].second;
        chk[xx][yy]=true;
        q.push(pii(xx,yy));
        int level=0;
        while(!q.empty()) {
            int sz=q.size();
            for(int w=0; w<sz; w++) {
                pii t=q.front(); q.pop();
                if(v[t.first][t.second]==3||v[t.first][t.second]==4) {
                    dist[z][pos[t.first][t.second]]=dist[pos[t.first][t.second]][z]=level;
                }
                for(int i=0; i<4; i++) {
                    int nx=t.first+dx[i],ny=t.second+dy[i];
                    if(nx<0||ny<0||nx>=n||ny>=n) continue;
                    if(v[nx][ny]==1) continue;
                    if(chk[nx][ny]) continue;
                    chk[nx][ny]=true;
                    q.push(pii(nx,ny));
                }
            } level++;
        }
    }

    memset(d,0x3f,sizeof(d));
    for(int i=1; i<snum; i++) {
        d[i][1|(1<<i)]=dist[0][i];
    }

    int lim=1<<snum, ans=-1;
    for(int bit=3; bit<lim; bit+=2) {
        for(int i=1; i<snum; i++) {
            if((bit>>i)&1) {
                int pbit = bit^(1<<i);
                if(i==snum-1 && d[i][bit]<=k) ans=max(ans,cnt(bit)-2);
                for(int j=1; j<snum-1; j++) {
                    if(i==j) continue;
                    if((pbit>>j)&1) {
                        d[i][bit] = min(d[i][bit],d[j][pbit]+dist[j][i]*cnt(pbit));
                        if(d[i][bit]>k) d[i][bit]=inf; //해당 비용이 c를 넘어서면 inf로 표시
                        else ans=max(ans,cnt(bit)-2);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

