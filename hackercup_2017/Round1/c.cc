#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;
int dist[102][102], d[5002][2][3], s[5002], e[5002], K;
const int inf = 0x3f3f3f3f;
int f(int k, int x, int r) {
    if(k<=0||k>K) return inf;
    int &ret = d[k][x][r];
    if(ret>=0) return ret;
    if(k==1&&x==0) return ret=dist[1][s[1]];
    else ret=inf;

    if(r==2) {
        ret = min(f(k,0,1)+dist[s[k]][e[k]], f(k-1,1,1)+dist[e[k-1]][e[k]]);
    } else if(r==1) {
        if(x==1) {
            if(k!=K) ret=f(k+1,0,0)+dist[s[k+1]][e[k]];
        } else ret=f(k-1,1,2)+dist[e[k-1]][s[k]];
    } else {
        ret = f(k-1,0,1)+dist[s[k-1]][s[k]];
        if(k!=1) ret = min(ret, f(k-2,1,1)+dist[e[k-2]][s[k]]);
    }
    if(ret>=inf) ret=inf;
    return ret;
}
int main() {
    freopen("./c_input.txt", "r", stdin);
    freopen("./c_output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        memset(dist,0x3f,sizeof(dist));
        memset(d,-1,sizeof(d));
        memset(s,0,sizeof(s));
        memset(e,0,sizeof(e));

        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        K=k;
        for(int i=0; i<=n; i++) dist[i][i]=0;
        for(int i=0; i<m; i++) {
            int x,y,g;
            scanf("%d%d%d",&x,&y,&g);
            dist[y][x]=dist[x][y]=min(dist[x][y],g);
        }

        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                if(i==k) continue;
                for(int j=1; j<=n; j++) {
                    if(i==j||j==k) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        for(int i=1; i<=k; i++) scanf("%d%d",&s[i],&e[i]);

        int ans = f(k,1,2);
        if(ans>=inf) ans=-1;
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
