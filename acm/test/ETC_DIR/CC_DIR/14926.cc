#include <cstdio>
#include <vector>
using namespace std;
int chk[501][501], work[501];
vector<int> v[501];
void dfs(int x) {
    printf("a%d ", x);
    for(int &iter=work[x]; iter<v[x].size(); iter++) {
        int y = v[x][iter];
        if(chk[x][y]) continue;
        chk[x][y]=chk[y][x]=true;
        dfs(y);
    }
}
int main() {
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            v[i].push_back(j);
        }
    }
    chk[1][n]=chk[n][1]=true;
    dfs(1);
    puts("a1");
    return 0;
}
