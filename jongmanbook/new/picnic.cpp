#include <bits/stdc++.h>
using namespace std;
bool chk[11];
bool f[11][11];
int n,m,ans;
void Dfs(int x, int y, int fcnt) {
    if(fcnt == n) {
        ans++;
        return;
    }
    for(int i=x+1; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(!chk[i] && !chk[j] && f[i][j]) {
                chk[i] = chk[j] = true;
                Dfs(i,j,fcnt+2);
                chk[i] = chk[j] = false;
            }
        }
    }
}
void init() {
    memset(f, false, sizeof(f));
    ans = 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        init();

        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int x,y; cin >> x >> y;
            f[x][y] = f[y][x] = true;
        }

        for (int j = 1; j < n; j++) {
            if (f[0][j]) {
                chk[0] = chk[j] = true;
                Dfs(0, j, 2);
                chk[0] = chk[j] = false;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}