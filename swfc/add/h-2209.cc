#include <iostream>
using namespace std;
#define L 0
#define R 1
#define D 2
int h[501][501], d[501][501][4];
bool chk[501][501][4];
int dx[] = { 0, 0, 1, -1 }, dy[] = { -1, 1, 0, 0 };
int n, m;
int dfs(int x, int y, int pdir) {
    if (x == n - 1 && y == m - 1) return d[x][y][pdir] = 1;
    if (chk[x][y][pdir]) return d[x][y][pdir];
    chk[x][y][pdir] = true;

    int &ret = d[x][y][pdir];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (h[nx][ny] < h[x][y]) {
            ret += dfs(nx, ny, i);
        }
    }
    return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &h[i][j]);
        }
    }
    printf("%d\n", dfs(0, 0, D));
    return 0;
}
