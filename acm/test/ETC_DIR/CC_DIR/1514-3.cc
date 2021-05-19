#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int c[]={0,1,1,1,2,2,2,1,1,1};
int now[102],dest[102],d[102][12][12];
int f(int x, int cur, int prev) {
    if(x<=2) return 0LL;

    int &ret = d[x][cur][prev];
    if(ret<inf) return ret;

    int cw_cnt = (dest[x]+10-cur)%10;
    int cost = c[cw_cnt];
    ret = min(ret, f(x-1, prev, now[x-2]) + cost);
    ret = min(ret, f(x-1, (prev+cw_cnt)%10, now[x-2]) + cost);
    ret = min(ret, f(x-1, (prev+cw_cnt)%10, (now[x-2]+cw_cnt)%10) + cost);
    return ret;
}
int main() {
    int n;
    scanf("%d", &n); n+=2;
    for(int i=3; i<=n; i++) scanf("%1d",&now[i]);
    for(int i=3; i<=n; i++) scanf("%1d",&dest[i]);
    now[n+1]=dest[n+1]=0;
    memset(d,0x3f,sizeof(d));

    printf("%d\n", f(n,now[n],now[n-1]));
    return 0;
}
