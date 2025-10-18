#include <bits/stdc++.h>
using namespace std;
int n;
int v[101][101];
int dp[101][101];
int f(int x, int y) {
    if(x<0||y<0||x>=n||y>=n) return 0;
    if(dp[x][y]>=0) return dp[x][y];

    int & ret = dp[x][y];
    ret=0;
    if(f(x+v[x][y],y)==1) ret=1;
    if(f(x,y+v[x][y])) ret=1;
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        memset(dp,-1,sizeof(dp));
        cin >> n;
        dp[n-1][n-1]=1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> v[i][j];
            }
        }

        if(f(0,0)) puts("YES");
        else puts("NO");
    }
    return 0;
}