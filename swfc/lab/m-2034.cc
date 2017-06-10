#include <iostream>
using namespace std;
bool chk[13][13];
bool col[13], cross1[26], cross2[26];
int n, ans=0;
bool has(int x, int y) {
    if(col[y]) return true;
    if(cross1[x+y]) return true;
    if(cross2[x-y+n-1]) return true;
    return false;
}
void dfs(int s, int x) {
    if(s==0) {
        ans++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (has(x, j)) continue;
        col[j] = cross1[x + j] = cross2[x - j + n - 1] = true;
        dfs(s - 1, x + 1);
        col[j] = cross1[x + j] = cross2[x - j + n - 1] = false;
    }

}
int main() {
    scanf("%d", &n);
    dfs(n,0);
    printf("%d", ans);
    return 0;
}
