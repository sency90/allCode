#include <cstdio>
using namespace std;
int n, ans;
bool c[15], cd[30], cu[30];
void dfs(int x, int pick) {
    if(pick == n){
        ans++;
        return;
    }
    for(int y=1; y<=n; y++) {
        if(c[y]) continue;
        if(!cd[x-y+(n-1)] && !cu[x+y]) {
            c[y] = cd[x-y+(n-1)] = cu[x+y] = true;
            dfs(x+1, pick+1);
            c[y] = cd[x-y+(n-1)] = cu[x+y] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(0,0);
    printf("%d\n", ans);
    return 0;
}
