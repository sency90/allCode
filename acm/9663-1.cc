#include <cstdio>
using namespace std;
int ans=0,n;
bool col[16], diax[31], diay[31];
inline int ABS(int x) { return (x<0)?-x:x; }
inline void dfs(int x) {
    if(x==n) {
        ans++;
        return;
    }
    for(int y=0; y<n; y++) {
        if(col[y]||diax[n+x-y-1]||diay[x+y]) continue;
        col[y]=diax[n+x-y-1]=diay[x+y]=true;
        dfs(x+1);
        col[y]=diax[n+x-y-1]=diay[x+y]=false;
    }
}
int main() {
    scanf("%d", &n);
    dfs(0);
    printf("%d", ans);
    return 0;
}
