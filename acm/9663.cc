#include <cstdio>
using namespace std;
int n, h[15], ans;
bool chk[15];
inline int ABS(int x) { return (x<0)?-x:x; }
inline void go(int x) {
    for(int i=1; i<x; i++) if(ABS(h[i]-h[x])==ABS(i-x)) return;
    if(x==n) {
        ans++;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        chk[i]=true;
        h[x+1]=i;
        go(x+1);
        chk[i]=false;
    }
}
int main() {
    scanf("%d", &n);
    go(0);
    printf("%d", ans);
    return 0;
}
