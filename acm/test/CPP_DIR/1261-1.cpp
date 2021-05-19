#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int map[101][101];
int check[101][101];
const int inf = 0x7fffffff;
int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(pair<int, int> p) {
    for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        if (nx < 1 || ny < 1 || nx > m || ny > n) continue; // 요부분 바꿨고요
        if (map[nx][ny] == 0)
        {
            if (check[nx][ny] > check[p.first][p.second]) {
                check[nx][ny] = check[p.first][p.second];
                dfs(make_pair(nx, ny));
            }
        }
        else if (map[nx][ny] == 1) // map[nx][ny] == 1 일때
        {
            if (check[nx][ny] > check[p.first][p.second] + 1) {
                check[nx][ny] = check[p.first][p.second] + 1;
                dfs(make_pair(nx, ny));
            }
        }
    }
}

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &map[i][j]);
            check[i][j] = inf;
        }
    }
    check[1][1] = 0;
    dfs(make_pair(1, 1));
    printf("%d\n", check[m][n]); //요부분도 바꿨어요
}
