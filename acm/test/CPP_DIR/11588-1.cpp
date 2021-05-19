#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[21];
bool chk[21];
int n, m;
int dfs(int x) {
    if(x==n) return 1;
    bool chkX = true;
    int res = 0;
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i]]) {
            chkX = false;
            break;
        }
    }
    if(chkX) {
        chk[x] = true;
        res+=dfs(x+1);
        chk[x] = false;
    }
    res+=dfs(x+1);
    return res;
}
int main() {
    int x, y;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d %d",&x,&y);
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    printf("%d", dfs(0));
    return 0;
}
