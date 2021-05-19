#include <stdio.h>
#include <string.h>
bool d[1001][1001], check[1001];
void dfs(short x) {
    check[x] = true;
    for(short i=1; i<=1000; i++) {
        if(check[i]) continue;
        else if(d[x][i]) dfs(i);
    }
}
int main() {
    memset(d, false, sizeof(d));
    memset(check, false, sizeof(check));
    int m;
    short n, x, y, cnt=0; scanf("%hd %d", &n, &m);
    for(int i=1; i<=m; i++) {
        scanf("%hd %hd", &x, &y);
        d[x][y] = true;
        d[y][x] = true;
    }

    for(short i=1; i<=n; i++) {
        if(!check[i]) {
            dfs(i);
            cnt++;
        }
    }
    printf("%hd", cnt);
    return 0;
}
