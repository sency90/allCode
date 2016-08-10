#include <stdio.h>
#include <vector>
using namespace std;
int c[201][201];
int add[201], arr[201];
vector<int> v[201];
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&w);
        if(s==e) if(c[s][e]<w) c[s][e]=w;
        else {
            if(c[s][e]==0||c[s][e]>w) c[s][e]=w;
            if(c[s][e]==0||c[e][s]>w) c[e][s]=w;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(c[i][j]==0) continue;
            v[i].push_back(j);
            if(i!=j) v[j].push_back(i);
        }
    }

    bool chk[201];
    for(int i=1; i<=n; i++) {
        start=i;
        memset(chk, false, sizeof(chk));
        chk[start]=true;
        q.push(start);
        while(!q.empty()) {
            x = q.front();
            for(int i=0; i<v[x].size(); i++) {
                if(chk[v[x][i]]) {
                    if(v[x][i]==x) add[x]=max(add[x],c[x][x]/2);
                    continue;
                }
                chk[v[x][i]] = true;
                (arr[v[x][i]],arr[v[x][i]])
                    q.push(v[x][i]);
            }
        }
    }
    return 0;
}
