#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int n;
struct Hint{
    int mx, cnt;
    Hint() {}
    Hint(int mx, int cnt):mx(mx),cnt(cnt) {}
};
Hint info[101][101];
Hint f(int x, int y) {
    if(y<0||y>=n) return Hint(0,0);
    if(x==n-1) return Hint(v[x][y],1);

    Hint & ret = info[x][y];
    if(ret.mx) return ret;

    Hint lhs = f(x+1,y);
    Hint rhs = f(x+1,y+1);
    ret.mx = max(lhs.mx, rhs.mx) + v[x][y];
    if(lhs.mx > rhs.mx) ret.cnt=lhs.cnt;
    else if(lhs.mx < rhs.mx) ret.cnt=rhs.cnt;
    else ret.cnt=lhs.cnt+rhs.cnt;
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        
        v.clear(); v.resize(n, vector<int>());
        for(int i=0; i<n; i++) {
            v[i].clear(); v[i].resize(i+1);
            for(int j=0; j<=i; j++) {
                cin >> v[i][j];
            }
        }

        memset(info, 0, sizeof(info));
        Hint ans = f(0,0);
        printf("%d\n", ans.cnt);
    }
    return 0;
}