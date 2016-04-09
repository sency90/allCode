#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char a[10][11];
int d[10][2], v[10], ans[10];
bool chk[10][2];
int dx[]={-1,0,1};
int dy[]={-1,-1,-1};
int f(int x, int i) {
    if(x<0) return 0;
    if(chk[x][i]) return d[x][i];
    chk[x][i] = true;
    d[x][0] = max(f(x-1,1), f(x-1,0));
    d[x][1] = max(f(x-2,1),f(x-2,0)) + ans[x];
    return d[x][i];
}
int main() {
    int t, n, m, r, cnt;
    scanf("%d", &t);
    while(t--) {
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        memset(chk, false, sizeof(chk));
        memset(ans, 0, sizeof(ans));
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%s", a[i]);
        }
        r=-1;
        cnt=0;
        bool htMerge;
        for(int j=0; j<m; j++) {
            htMerge = true;
            for(int i=0; i<n; i++) {
                if(a[i][j]=='.') {
                    v[j-cnt]++;
                    int nx, ny;
                    for(int p=0; p<3; p++) {
                        nx = i+dx[p];
                        ny = j+dy[p];
                        if(nx<0||ny<0||nx>=n||ny>=m) continue;
                        if(a[nx][ny]=='.') htMerge = false;
                    }
                }
            }
            if(j!=0 && htMerge) {
                ans[r]+=v[j-cnt];
                v[j-cnt]=0;
                cnt++;
            } else {
                ans[++r]=v[j-cnt];
            }
        }
        int t1=f(r,0), t2=f(r,1);
        printf("%d\n", t1>t2?t1:t2);
    }
    return 0;
}
