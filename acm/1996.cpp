#include <stdio.h>
#include <cstring>
using namespace std;
char mp[1000][1001];
int ans[1000][1000], n;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
void check(int x, int y) {
    int nx, ny;
    for(int i=0; i<8; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if(ans[nx][ny]<0) continue;
        ans[nx][ny]+=mp[x][y]-'0';
        if(ans[nx][ny]>=10) ans[nx][ny]=-2;
    }
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", mp[i]);
        for(int j=0; j<n; j++) {
            if(mp[i][j]!='.' && ans[i][j]!='*') {
                ans[i][j]=-1;
                check(i,j);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(ans[i][j] >= 0) printf("%d", ans[i][j]);
            else if(ans[i][j]==-1) putchar('*');
            else putchar('M');
        } puts("");
    }
}
