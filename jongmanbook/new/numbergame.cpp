#include <bits/stdc++.h>
using namespace std;
int n;
int v[51];
int dp[51][51][2];
bool chk[51][51][2];
const int INF = 0x3f3f3f3f;
int f(int x, int y, int p) {
    if(x>y || (x<0||y<0||x>=n||y>=n)) {
        return 0;
    }
    else if(x==y) {
        if(p==0) return v[x];
        else return -v[x];
    }
    int &ret = dp[x][y][p];

    if(chk[x][y][p]) return ret;
    chk[x][y][p] = true;

    if(p==0) {
        ret = -INF;
        ret = max({ret, f(x+1,y,p^1)+v[x], f(x,y-1,p^1)+v[y], f(x+2,y,p^1), f(x,y-2,p^1)});
    }
    else {
        ret = INF;
        ret = min({ret, f(x+1,y,p^1)-v[x], f(x,y-1,p^1)-v[y], f(x+2,y,p^1), f(x,y-2,p^1)});
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }

        memset(chk,false,sizeof(chk));
        printf("%d\n", f(0,n-1,0));
    }
    return 0;
}