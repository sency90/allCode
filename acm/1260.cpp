#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<short> q;
bool d[1001][1001];
bool check[1001];
void dfs(short y) {
    check[y] = true;
    printf("%hd ", y);
    for(short i=1; i<=1000; i++) {
        if(check[i]) continue;
        else if(d[y][i]) dfs(i);
    }
}
void bfs(short x) {
    for(short i=1; i<=1000; i++) {
        if(check[i]) continue;
        else if(d[x][i]) {
            check[i] = true;
            printf("%hd ", i);
            q.push(i);
        }
    }
    short temp;
    while(!q.empty()) {
        temp = q.front(); q.pop();
        bfs(temp);
    }
}
int main() {
    memset(d, false, sizeof(d));
    memset(check, false, sizeof(check));
    short n, m, v, x, y;
    scanf("%hd %hd %hd", &n, &m, &v);
    for(short i=0; i<m; i++) {
        scanf("%hd %hd", &x, &y);
        d[x][y] = true;
        d[y][x] = true;
    }

    check[v] = true;
    dfs(v);
    printf("\n");

    memset(check, false, sizeof(check));
    check[v] = true;
    printf("%hd ", v);
    bfs(v);
    return 0;
}
