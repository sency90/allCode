#include <iostream>
#include <algorithm>
using namespace std;
#define R 0
#define L 1
#define D 2
int n;
int v[1001][1001], d[1001][1001][3];
bool chk[1001][1001][3];
int dx[]={0,0,1}, dy[]={1,-1,0};
const int inf = 0x3f3f3f3f;
int f(int x, int y, int pdir) {
    if(x==n-1 && y==n-1) return v[x][y];
    if(chk[x][y][pdir]) return d[x][y][pdir];
    chk[x][y][pdir]=true;

    int &ret = d[x][y][pdir];
    ret=-inf;
    for(int i=0; i<3; i++) {
        if(pdir==i||i==D||pdir==D) {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            ret = max(ret, f(nx,ny,i)+v[x][y]);
        }
    }
    return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &v[i][j]);
        }
    }
    printf("%d", f(0,0,D));
    return 0;
}
