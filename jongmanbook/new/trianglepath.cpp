#include <bits/stdc++.h>
using namespace std;
int v[101][101];
int dp[101][101];
int n;
int f(int x, int y) {
    if(x==n-1) return v[x][y];
    if(dp[x][y]) return dp[x][y];

    int & ret = dp[x][y];
    ret = max(f(x+1,y), f(x+1,y+1))+v[x][y];
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc; 
    while(tc--) {
        cin >> n;

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                cin >> v[i][j];
            }
        }

        memset(dp, 0, sizeof(dp));
        printf("%d\n", f(0,0));
    }
    return 0;
}