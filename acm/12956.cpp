#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int v[101][101], u[101][101], ori[101][101];
queue<pair<int,int> > q;
int main() {
    int n, m, s, e, t;
    scanf("%d%d",&n,&m);
    memset(v, 0x3f, sizeof(v));
    memset(u, 0x3f, sizeof(u));
    memset(ori, 0x3f, sizeof(ori));
    for(int i=0; i<m; i++) {
        scanf("%d%d%d",&s,&e,&t);
        v[s][e]=v[e][s]=u[s][e]=u[e][s]=ori[s][e]=ori[e][s]=t;
        q.push(make_pair(s,e));
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][k]+v[k][j] > 0x3f3f3f3f) continue;
                if(v[i][j]>v[i][k]+v[k][j]) v[i][j] = v[i][k]+v[k][j];
            }
        }
    }

    while(!q.empty()) {
        s=q.front().first; e=q.front().second; q.pop();
        u[s][e]=u[e][s]=0x3f3f3f3f;
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(u[i][k]+u[k][j] > 0x3f3f3f3f) continue;
                    if(u[i][j]>u[i][k]+u[k][j]) u[i][j] = u[i][k]+u[k][j];
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(u[i][j]!=v[i][j]) {
                    cnt++;
                }
                u[j][i]=u[i][j]=ori[i][j];
            }
        }
        printf("%d ", cnt);
    }
    printf("\n");
    return 0;
}
