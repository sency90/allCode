#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
bool chk[29][29];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;
double ans=0, p=0, di[4];
void dfs(int x, int y, double pr, int cnt) {
    chk[x][y] = true;
    if(cnt == n) {
        ans+=pr;
        return;
    }
    int nx, ny;
    for(int i=0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if(chk[nx][ny]) continue;
        dfs(nx, ny, pr*di[i], cnt+1);
        chk[nx][ny]=false;
    }
}
int main() {
    memset(chk, false, sizeof(chk));
    scanf("%d", &n);
    for(int i=0; i<4; i++) {
        scanf("%lf", &di[i]);
        di[i]/=100;
    }
    dfs(n,n,1.0,0);
    printf("%.10lf", ans);
    return 0;
}
