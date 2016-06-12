#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[21];
bool vis[21];
int n;
int dfs(int x) {
    if(x>n) return 1;
    int ans = dfs(x+1);
    bool checkX = true;
    for(int i=0; i<v[x].size(); i++) {
        if(vis[v[x][i]]) checkX = false;
    }
    if(checkX) {
        vis[x] = true;
        ans += dfs(x+1);
        vis[x] = false;
    }
    return ans;
}
int main() {
    int m, x, y;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    printf("%d", dfs(1));
    return 0;
}
