#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int p[100001][18], d[100001];
bool chk[100001];
vector<vector<int> > v;
int main() {
    int tc,n,Q;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d",&n,&Q);
        v.resize(n+1, vector<int>());
        for(int i=1; i<n; i++) {
            scanf("%d", &p[i][0]);
            v[i].push_back(p[i][0]);
            v[p[i][0]].push_back(i);
        }

        queue<int> q;
        q.push(0); chk[0] = true;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(int i=0; i<v[x].size(); i++) {
                if(chk[v[x][i]]) continue;
                chk[v[x][i]] = true;
                d[v[x][i]] = d[x]+1;
                for(int j=1; (1<<j)<=d[v[x][i]]; j++) {
                    p[v[x][i]][j] = p[ p[v[x][i]][j-1] ][j-1];
                }
                q.push(v[x][i]);
            }
        }

        int a,b;
        for(int i=0; i<Q; i++) {
            int cnt=0;
            scanf("%d%d",&a,&b);
            if(d[a]>d[b]) swap(a,b);
            while(d[a]!=d[b]) {
                int level=0;
                for(; (1<<level)<=d[b]-d[a]; level++);
                b=p[b][--level];
                cnt+=(1<<level);
            }

            while(true) {
                int level = -1;
                int x = b;
                while(d[a]<d[x]) {
                    b=p[x][++level];
                }
                if(level==-1) break;
                else cnt+=(1<<level);
                if(d[a]==d[x]) {
                    b=x;
                    break;
                }
            }
            while(a!=b) {
                if(p[a][0]==p[b][0]) {
                    cnt+=2;
                    break;
                }
                for(int level=1; ; level++) {
                    if(p[a][level] == p[b][level]) {
                        a=p[a][level-1];
                        b=p[b][level-1];
                        cnt+=(1<<level); //cnt+=(1<<(level-1))*2;
                        break;
                    }
                }
            }
            printf("%d\n", cnt);
        }
        v.clear();
        memset(p, 0, sizeof(p));
        memset(chk, false, sizeof(chk));
    }
    return 0;
}
