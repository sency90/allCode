#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N2 (N<<1)
#define i2 (i<<1)
#define j2 (j<<1)
vector<pii> co;
vector<vector<int>> v;
int src, sink;
int r[202][202], parent[202];
void conn(int x, int y) {
    if(r[x][y]) return;
    v[x].push_back(y);
    v[y].push_back(x);
    r[x][y]=1;
}
bool overlap(pii &a, pii b, int D) {
    int x=a.first-b.first, y=a.second-b.second;
    return (x*x+y*y<=D);
}
int main() {
    int L,W,N,d;
    for(int z=1; scanf("%d%d%d%d",&L,&W,&N,&d); z++) {
        if(!L&&!W&&!N&&!d) return 0;
        memset(r,0,sizeof(r));
        co.clear();
        v.clear(); v.resize(N2+2, vector<int>());
        int tf=0, D=4*d*d;
        pii c;
        src=N2; sink=N2|1;
        for(int i=0; i<N; i++) {
            int x,y; scanf("%d%d", &x,&y);
            c=make_pair(x,y);
            conn(i2,i2|1);
            if(y<=d) conn(src,i2);
            if(y+d>=W) conn(i2|1,sink);
            for(int j=0; j<co.size(); j++) {
                if(overlap(co[j],c,D)) {
                    conn(i2|1,j2);
                    conn(j2|1,i2);
                }
            }
            co.push_back(c);
        }

        while(true) {
            memset(parent,-1,sizeof(parent));
            queue<int> q;
            q.push(src); parent[src]=src;
            while(!q.empty() && parent[sink]==-1) {
                int x = q.front(); q.pop();
                for(int y: v[x]) {
                    if(r[x][y]>0 && parent[y]<0) {
                        parent[y]=x;
                        q.push(y);
                    }
                }
            }
            if(parent[sink]==-1) break;
            int f = 0x3f3f3f3f;
            for(int i=sink; i!=src; i=parent[i]) f = min(f, r[parent[i]][i]);
            for(int i=sink; i!=src; i=parent[i]) {
                r[parent[i]][i]-=f;
                r[i][parent[i]]+=f;
            } tf+=f;
        }
        printf("Case %d: %d\n", z, tf);
    }
    return 0;
}
