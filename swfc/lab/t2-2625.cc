#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[11],d[11][10001];
int n,m;
bool chk[11][10001];
const int inf = 0x3f3f3f3f;
int f(int x,int y) {
    if(x==0&&y==0) return 0;
    else if(x<=0||y<=0) return inf;
    int &ret = d[x][y];
    if(chk[x][y]) return ret;
    chk[x][y]=true;

    for(int i=1; i*i<=y; i++) {
        ret = min(ret,f(x-1,y-i*i)+(v[x]-i)*(v[x]-i));
    }
    return ret;
}
int main() {
    //freopen("input.txt","r",stdin);
    memset(d,0x3f,sizeof(d));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d",&v[i]);
    }
    int ans=f(n,m);
    if(ans==inf) puts("-1");
    else printf("%d\n",ans);
    return 0;
}
