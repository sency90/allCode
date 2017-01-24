#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define nd2 (nd<<1)
#define nnd2 (nnd<<1)
typedef pair<int,int> pii;
vector<pii> cox,coy,co;
vector<int> v[3000];
int r[3000][3000];
map<int,int> X,Y,Xidx,Yidx;
int main() {
    int n,m; scanf("%d%d",&n,&m);
    //cox[0].X=coy[0].X=1;
    co.emplace_back(pii(0,0));
    cox.emplace_back(pii(0,0));
    coy.emplace_back(pii(0,0));
    for(int i=1; i<=7; i++) { int x,y;
        scanf("%d%d",&x,&y);
        co.emplace_back(pii(x,y));
        cox.emplace_back(pii(x,x));
        coy.emplace_back(pii(y,y));
    }
    for(int i=0; i<co.size(); i++) {
        for(int j=0; j<co.size(); j++) {
            if(i==j) continue;
            if(co[i].first==co[j].first && co[i].second==co[j].second) {
                return 0&puts("NO");
            }
        }
    }
    co.emplace_back(pii(n,m));
    cox.emplace_back(pii(n,n));
    coy.emplace_back(pii(m,m));

    sort(cox.begin(), cox.end());
    sort(coy.begin(), coy.end());

    //pii => first: changed value, second: original value.
    for(int i=1; i<=8; i++) {
        int difx = cox[i].first-cox[i-1].second;
        cox[i].first = cox[i-1].first + ((difx>3)? 3:difx);

        int dify = coy[i].first-coy[i-1].second;
        coy[i].first = coy[i-1].first + ((dify>3)? 3:dify);
        //printf("[%d] %d %d (%d,%d)\n",i,difx,dify,cox[i].first,coy[i].first);
    }

    for(int i=0; i<=8; i++) {
        for(int j=0; j<=8; j++) {
            for(auto &p: co) {
                if(p.first==cox[i].second && p.second==coy[j].second) {
                    p.first=cox[i].first;
                    p.second=coy[j].first;
                }
            }
        }
    }
    int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
    int x_mx=0, y_mx=0;
    for(auto &p: co) {
        //printf("co.x:%d co.y:%d\n", p.first, p.second);
        x_mx = max(x_mx, p.first);
        y_mx = max(y_mx, p.second);
    }

    auto mkedge = [](int x, int y) {
        if(!r[x][y]&&!r[y][x]) {
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        r[x][y]=1;
    };
    auto mkno = [y_mx](int x, int y) {
        return x*y_mx+y;
    };

    bool cherry[60][60], straw[60][60], candle[60][60];
    int src=mkno(x_mx,0)<<1, snk=(mkno(x_mx,0)<<1)+1;
    for(int i=2; i<=7; i++) {
        int x=co[i].first-1, y=co[i].second-1;
        int nd = mkno(x,y);
        if(i<=4) {
            cherry[x][y]=true;
            mkedge(src, nd2);
        } else {
            straw[x][y]=true;
            mkedge(nd2+1,snk);
        }
    }
    candle[co[1].first-1][co[1].second-1]=true;
    //printf("x_mx:%d, y_mx:%d\n",x_mx, y_mx);
    for(int i=0; i<x_mx; i++) {
        for(int j=0; j<y_mx; j++) {
            if(candle[i][j]) continue;
            int nd = mkno(i,j);
            mkedge(nd2, nd2+1);
            if(straw[i][j]) continue;
            for(int k=0; k<4; k++) {
                int nx=i+dx[k], ny=j+dy[k];
                if(candle[nx][ny]||cherry[nx][ny]) continue;
                if(nx<0||ny<0||nx>=x_mx||ny>=y_mx) continue;
                int nnd = mkno(nx,ny);
                mkedge(nd2+1,nnd2);
            }
        }
    }

    int p[3000];
    int ans=0;
    while(true) {
        memset(p,-1,sizeof(p));
        queue<int> q; q.push(src); p[src]=src;
        while(!q.empty() && p[snk]==-1) {
            int x = q.front(); q.pop();
            for(int y: v[x]) {
                if(p[y]==-1 && r[x][y]>0) {
                    p[y]=x;
                    q.push(y);
                }
            }
        }
        if(p[snk]==-1) break;
        int mnf=0x3f3f3f3f;
        for(int i=snk; i!=src; i=p[i]) mnf = min(mnf,r[p[i]][i]);
        for(int i=snk; i!=src; i=p[i]) {
            r[p[i]][i]-=mnf;
            r[i][p[i]]+=mnf;
        }
        ans+=mnf;
    }
    if(ans==3) puts("Yes");
    else puts("No");
    return 0;
}
