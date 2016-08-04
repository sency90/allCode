#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[100001];
queue<int> q;
int d[100001], p[100001][17];
bool chk[100001];
int main() {
    int n, m, x, y, tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &n,&m);
        for(int i=1; i<n; i++) {
            scanf("%d",&p[i][0]);
            v[i].push_back(p[i][0]);
            v[p[i][0]].push_back(i);
        }

        q.push(0); chk[0] = true; d[0] = 0;
        while(!q.empty()) {
            x = q.front(); q.pop();
            for(int i=0; i<v[x].size(); i++) {
                if(chk[v[x][i]]) continue;
                chk[v[x][i]] = true;
                p[v[x][i]][0] = x;
                d[v[x][i]] = d[x]+1;
                for(int j=1; (1<<j)<=d[v[x][i]]; j++) {
                    p[v[x][i]][j] = p[ p[v[x][i]][j-1] ][j-1];
                }
                q.push(v[x][i]);
            }
        }

        int i;
        while(m--) {
            int cnt=0;
            scanf("%d%d",&x,&y);
            if(d[x]<d[y]) swap(x,y);

            while(d[x]!=d[y]) {
                for(i=0; (1<<i)<=d[x]-d[y]; i++);
                x = p[x][--i];
                cnt += (1<<i);
            }

            while(x!=y) {
                for(i=0; p[x][i]!=p[y][i]; i++) {
                    if(p[x][i] == p[y][i]) break;
                }

                if(i==0) {
                    x = p[x][i];
                    y = p[y][i];
                    cnt+=2;
                    break;
                } else {
                    cnt+=(1<<i);
                    i--;
                    x = p[x][i];
                    y = p[y][i];
                }
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
