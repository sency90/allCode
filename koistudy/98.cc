#include <stdio.h>
int v[10][10], dx[]={0,1}, dy[]={1,0};
void dfs(int x, int y) {
    if(v[x][y]==2) {
        v[x][y]=9;
        return;
    }
    v[x][y] = 9;
    for(int i=0; i<2; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(nx>=10 || ny>=10) continue;
        if(v[nx][ny]==1) continue;
        if(v[nx][ny]==0||v[nx][ny]==2) {
            dfs(nx,ny);
            break;
        }
    }
}
int main() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    if(v[1][1]!=1) dfs(1,1);
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%d ", v[i][j]);
        }
        puts("");
    }

    return 0;
}
