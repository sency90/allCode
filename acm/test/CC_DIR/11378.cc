#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[2002];
int r[2002][2002], p[2002], cnt[1001], src, sink;
void input(int x, int y, int w) {
    if(!r[x][y]) {
        v[x].push_back(y);
        v[y].push_back(x);
        r[x][y]=1;
    }
}
int maxFlow(int lim) {
    int ans=0;
    while(true) {
        memset(p, -1, sizeof(p));
        queue<int> q;
        q.push(src); p[src]=src;
        while(!q.empty()&&p[sink]==-1) {
            int x=q.front(); q.pop();
            for(auto &y:v[x]) {
                if(p[y]!=-1||r[x][y]<=0) continue;
                p[y]=x;
                q.push(y);
            }
        }
        if(p[sink]==-1) break;
        int f=lim;
        for(int i=sink; i!=src; i=p[i]) f=min(f,r[p[i]][i]);
        if(f>lim) f=lim;
        lim-=f;
        for(int i=sink; i!=src; i=p[i]) {
            r[p[i]][i]-=f; r[i][p[i]]+=f;
        }
        ans+=f;
        if(lim==0) break;
    }
    return ans;
}
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    src=0; sink=n+m+1;
    for(int i=1; i<=n; i++) {
        input(src,i,1);
        scanf("%d", &cnt[i]);
        for(int j=0; j<cnt[i]; j++) {
            int x; scanf("%d",&x);
            input(i,x+n,1);
            input(x+n,sink,1);
        }
    }

    const int inf=0x3f3f3f3f;
    int ans=maxFlow(inf);
    for(int i=1; i<=n; i++) {
        if(!cnt[i]) continue;
        r[src][i]+=cnt[i]-1;
    }
    ans+=maxFlow(k);
    printf("%d\n", ans);
    return 0;
}
