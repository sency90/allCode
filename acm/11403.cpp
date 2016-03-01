#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int d, n, idx;
bool rchk[101][101];
bool chk[101][101];
vector<int> v[101];
void dfs(int x, int y) {
    if(!rchk[idx][y]) rchk[idx][y] = true;
    if(!chk[x][y]) chk[x][y] = true;
    for(int i=0; i<v[y].size(); i++) {
        if(chk[y][v[y][i]]) continue;
        dfs(y, v[y][i]);
    }
}
int main() {
    scanf("%d", &n);
    memset(rchk, false, sizeof(rchk));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &d);
            if(d==1) v[i].push_back(j);
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<v[i].size(); j++) {
            memset(chk, false, sizeof(chk));
            idx = i;
            dfs(i, v[i][j]);
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(rchk[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }

    return 0;
}
