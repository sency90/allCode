#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<ll, int> ans;
ll rx,ry,x,y;
int main() {
    int n,m,k,cnt=0;
    scanf("%d%d%d",&n,&m,&k);
    ans[0LL]=0;
    auto mv = [&]() {
        cnt++; x++, y++;
        if(x>=n) rx=(n<<1)-x;
        else rx=x;
        if(rx==0) x=0;

        if(y>=m) ry=(m<<1)-y;
        else ry=y;
        if(ry==0) y=0;

        ll idx = rx*100000LL+ry;
        if(ans.count(idx)) return;
        ans[idx]=cnt;
    };
    while(true) {
        mv();
        if((rx==0&&ry==m)||(rx==n&&ry==0)||(rx==n&&ry==m)) break;
    }
    for(int i=0; i<k; i++) {
        ll x,y; scanf("%lld%lld",&x,&y);
        ll idx = x*100000LL+y;
        if(ans.count(idx)) printf("%d\n", ans[idx]);
        else puts("-1");
    }
    return 0;
}
