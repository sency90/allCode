#include <bits/stdc++.h>
using namespace std;
int v[501];
int dp[501];
int f(int x) {
    if(x==0) return 1;
    if(dp[x]) return dp[x];

    int & ret = dp[x];
    ret=1;
    for(int i=0; i<x; i++) {
        if(v[i]<v[x]) ret = max(ret, f(i)+1);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        memset(dp, 0, sizeof(dp));

        int mx=0;
        for(int i=0; i<n; i++) {
            mx = max(mx, f(i));
        }
        printf("%d\n", mx);
    }
    return 0;
}