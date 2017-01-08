#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define i2 (i<<1)
#define j2 (j<<1)
#define N2 (N<<1)
using namespace std;
typedef pair<int,int> pii;
vector<pii> co;
vector<int> p;
int L,W,N,d,src,sink;
bool overlap(pii &a, pii &b, const int D) {
    int x=a.first-b.first, y=a.second-b.second;
    return (x*x+y*y<=D);
}
vector<vector<int> > v;
int r[202][202];
const int inf = 0x3f3f3f3f;
void conn(int i, int j) {
    if(r[i][j]) return;
    v[i].push_back(j);
    v[j].push_back(i);
    r[i][j]=1;
}
int main() {
    for(int z=1; scanf("%d%d%d%d",&L,&W,&N,&d); z++) {
        if(!L&&!W&&!N&&!d) return 0;
        int tf=0;
        const int D=4*d*d;
        src=N2; sink=N2|1;
        co.clear();
        v.clear(); v.resize(N2+2, vector<int>());
        memset(r, 0, sizeof(r));
        pii c;
        for(int i=0; i<N; i++) {
            scanf("%d%d",&c.first, &c.second);
            conn(i2,i2+1);
            if(c.second<=d) conn(src,i2);
            if(c.second+d>=W) conn(i2+1,sink);
            for(int j=0; j<co.size(); j++) {
                if(overlap(co[j],c,D)) {
                    conn(i2+1,j2);
                    conn(j2+1,i2);
                }
            }
            co.emplace_back(c);
        }

        while(true) {
            p.clear(); p.resize(N2+2, -1);
            queue<int> q; q.push(src); p[src]=src;
            while(!q.empty() && p[sink]==-1) {
                int x = q.front(); q.pop();
                for(int y: v[x]) {
                    if(r[x][y]>0 && p[y]==-1) {
                        p[y]=x;
                        q.push(y);
                    }
                }
            }
            if(p[sink]==-1) break;
            int f = inf;
            for(int i=sink; i!=src; i=p[i]) f=min(f,r[p[i]][i]);
            for(int i=sink; i!=src; i=p[i]) {
                r[p[i]][i]-=f;
                r[i][p[i]]+=f;
            } tf+=f;
        }
        printf("Case %d: %d\n", z, tf);
    }
    return 0;
}
