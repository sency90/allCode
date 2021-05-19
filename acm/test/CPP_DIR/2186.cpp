#include <stdio.h>
#include <cstring>
using namespace std;
char str[81], v[100][101];
int d[81][100][100];
signed char n, m, k, len;
signed char dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int dfs(int idx, int x, int y) {
    if(d[idx][x][y]!=-1) return d[idx][x][y];
    if(idx==len-1) return d[idx][x][y]=1;
    int nx, ny, tmp=0;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<4; j++) {
            nx = x+dx[j]*i;
            ny = y+dy[j]*i;
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(str[idx+1] != v[nx][ny]) continue;
            tmp += dfs(idx+1, nx, ny);
        }
    }
    return d[idx][x][y]=tmp;
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%hhd %hhd %hhd", &n, &m, &k);
    for(int i=0; i<n; i++) {
        scanf("%s", v[i]);
    }
    scanf("%s", str);
    len = strlen(str);
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(str[0] == v[i][j]) {
                sum += dfs(0,i,j);
            }
        }
    }
    printf("%d", sum);
    return 0;
}
