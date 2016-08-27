#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int win[200], r[200][200], p[200], cnt[20];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m,x,y,mx;
        scanf("%d%d",&n,&m);
        memset(r, 0, sizeof(r));
        memset(win, 0, sizeof(win));
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) {
            scanf("%d", &win[i]);
            if(i==0) mx=win[0];
            else mx = max(mx, win[i]+1);
        }

        //선수번호 [0,n), 경기번호 [13, n+m], src = n, sink = 12+m+1;
        int src=12, sink=13+m;
        for(int i=1; i<=m; i++) {
            r[src][12+i]=1;
            scanf("%d%d", &x,&y);
            r[12+i][x]=r[12+i][y]=1;
            cnt[x]++; cnt[y]++;
        }

        int totalFlow=0, ans=-1;
        for(int tw=mx; tw<=win[0]+cnt[0]; tw++) {
            if(tw==mx) {
                for(int i=0; i<n; i++) {
                    if(i==0) r[0][sink] = tw-win[0];
                    else r[i][sink] = (tw-1)-win[i];
                }
            } else {
                for(int i=0; i<n; i++) {
                    if(i==0) r[0][sink]++;
                    else r[i][sink]++;
                }
            }

            while(true) {
                queue<int> q;
                memset(p, -1, sizeof(p));
                q.push(src); p[src]=src;
                while(!q.empty() && p[sink]==-1) {
                    int x=q.front(); q.pop();
                    for(int i=0; i<=sink; i++) {
                        if(p[i]!=-1||r[x][i]<=0) continue;
                        p[i]=x; q.push(i);
                    }
                }
                if(p[sink]==-1) break;
                int f = inf;
                for(int i=sink; i!=src; i=p[i]) {
                    f = min(f, r[p[i]][i]);
                }
                for(int i=sink; i!=src; i=p[i]) {
                    r[p[i]][i] -= f;
                    r[i][p[i]] += f;
                }
                totalFlow += f;
            }
            if(totalFlow == m) { ans = tw; break; }
        }
        printf("%d\n", ans);
    }
    return 0;
}
