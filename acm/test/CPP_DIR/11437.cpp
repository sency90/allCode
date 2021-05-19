#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[50001];
queue<int> q;
int d[50001], p[50001][17];
bool chk[50001];
int main() {
    int n, m, x, y;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(1); chk[1] = true; d[1] = 0;
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

    scanf("%d", &m);
    int i;
    while(m--) {
        scanf("%d%d",&x,&y);
        if(d[x]<d[y]) swap(x,y);

        while(d[x]!=d[y]) {
            for(i=0; (1<<i)<=d[x]-d[y]; i++);
            x = p[x][--i];
        }

        while(x!=y) {
            for(i=0; p[x][i]!=p[y][i]; i++) {
                if(p[x][i] == p[y][i]) break;
            }

            if(i==0) {
                x = p[x][i];
                y = p[y][i];
                break;
            } else {
                i--;
                x = p[x][i];
                y = p[y][i];
            }
        }
        printf("%d\n", x);
    }
    return 0;
}
