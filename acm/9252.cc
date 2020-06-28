#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
struct Info{
    int cnt,x,y;
    Info():cnt(0),x(-1),y(-1){}
    Info(int cnt, int x, int y):cnt(cnt),x(x),y(y){}
    bool operator<(const Info &rhs) const {
        return cnt < rhs.cnt;
    }
    bool operator<=(const Info &rhs) const {
        return cnt <= rhs.cnt;
    }
};
bool chk[1001][1001];
Info dp[1001][1001];
pii p[1001][1001],mxi;

string a,b;
int mx;
Info f(int x, int y) {
    if(x<0||y<0) return Info(0,-1,-1);

    Info &ret = dp[x][y];
    if(chk[x][y]) return ret;

    chk[x][y] = true;
    ret = max(f(x-1,y),f(x,y-1));

    if(a[x]==b[y]) {
        if(ret <= f(x-1,y-1)) {
            ret = f(x-1,y-1);
            p[x][y] = pii(ret.x, ret.y);
            ret = Info(ret.cnt+1, x,y);
            if(mx < ret.cnt) {
                mx = ret.cnt;
                mxi = pii(x,y);
            }
        }
    }
    return ret;
}

string ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(p,-1,sizeof(p));
    cin >> a >> b;
    f(a.size()-1, b.size()-1);

    printf("%d\n", mx);
    if(mx!=0) {
        for(pii k=mxi; k.first>=0; k=p[k.first][k.second]) ans += a[k.first];
        for(int i=ans.size()-1; i>=0; i--) printf("%c", ans[i]);
        puts("");
    }
    return 0;
}
