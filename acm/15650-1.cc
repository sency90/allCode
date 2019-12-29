#include <cstdio>
using namespace std;
int get[8];
int n,m;
void dfs(int start, int pick) {
    if(pick == m) {
        for(int i=0; i<m; i++) printf("%d ", get[i]);
        puts("");
        return;
    }
    else if(pick>m) return;

    for(int i=start; i<=n; i++) {
        get[pick] = i;
        dfs(i+1, pick+1);
    }
}
int main() {
    scanf("%d%d", &n,&m);
    dfs(1,0);
    return 0;
}
