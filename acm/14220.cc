#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int v[501][501], d[501][501];
const int inf = 0x3f3f3f3f;
int n;
//현재 위치가 pos이고 방문한 도시 개수가 r일때 지금까지 움직인 거리 (최소값)
int f(int pos, int r) {
    if(r==1) return 0;
    int &ret = d[pos][r];
    if(ret>=0) return ret;
    else ret=inf;
    for(int i=0; i<n; i++) {
        if(v[pos][i]) ret=min(ret,f(i,r-1)+v[pos][i]);
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    int ans=inf;
    memset(d,-1,sizeof(d));
    for(int i=0; i<n; i++) {
        ans = min(ans,f(i,n));
    }
    if(ans>=inf) puts("-1");
    else printf("%d", ans);
    return 0;
}
