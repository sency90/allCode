#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<int> v[31];
vector<pll> co(31);
int mask[31], f=(1<<4)-1;
int mulx[]={1,0,-1,0}, muly[]={0,1,0,-1};
int nexdir[]={2,1,3,0}, opdir[]={2,3,0,1};
ll d[]={1LL<<31,1LL<<30,1LL<<31,1LL<<30};
void on(int &bit, int &pos) { bit|=(1<<pos); }
inline bool ison(int bit, int pos) { return (bit>>pos)&1; }
bool dfs(int x, int px, int dir, int dep, ll cx, ll cy) {
    bool ret=false;
    printf("x:%d px:%d dir:%d dep:%d cx:%lld cy:%lld\n",x,px,dir,dep,cx,cy);
    co[x]={cx,cy};
    for(int i=0,fd=dir; i<v[x].size(); fd=nexdir[fd], i++) {
        int y=v[x][i];
        if(y==px) continue;
        if(mask[x] == f) return true;
        for(int fd=dir; mask[y]!=f; fd=nexdir[fd]) {
            if(ison(mask[y],opdir[fd])) continue;
            if(y==4 && x==2) printf("fd: %d\n",fd);
            on(mask[x],fd); on(mask[y],opdir[fd]);
            ret|=dfs(y,x,fd,dep+1, cx+mulx[fd]*d[fd]/(1LL<<(dep+1)), cy+muly[fd]*d[fd]/(1LL<<(dep+1)));
        }
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(dfs(1,1,0,0,0LL,0LL)) puts("NO");
    else {
        puts("YES");
        for(int i=1; i<=n; i++) {
            printf("%lld %lld\n", co[i].first, co[i].second);
        }
    }
    return 0;
}
