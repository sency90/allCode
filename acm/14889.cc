#include <cstdio>
#include <cstring>
using namespace std;
int v[21][21], n, diff;
int l[11], r[11];
inline int ABS(int x) { return (x<0)?-x:x; }
inline int MIN(int x, int y) { return (x<y)?x:y; }
int getans() {
    int L=0, R=0, m=n/2;

    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            L += v[l[i]][l[j]] + v[l[j]][l[i]];
            R += v[r[i]][r[j]] + v[r[j]][r[i]];
        }
    }

    return ABS(L-R);
}
int ans = 0x3f3f3f3f;
void dfs(int x, int p, int bit) {
    if(p==n/2) {
        int lidx=0, ridx=0;
        for(int i=0; i<n; i++) {
            if(((bit>>i)&1) == 1) l[lidx++]=i;
            else r[ridx++]=i;
        }
        ans = MIN(ans, getans());
        return;
    }
    else if(x>=n || p>=n/2) return;

    dfs(x+1,p,bit);
    dfs(x+1,p+1,bit|(1<<x));
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
