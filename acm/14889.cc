#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, v[21][21], sum;
int mn = 0x3f3f3f3f;
bool chk[21];
int diff(int x, int y) {
    return (x<y)?y-x:x-y;
}
void dfs(int x, int pick, int ans) {
    if(pick == (n>>1)) {
        mn = min(mn,diff(sum-ans, ans));
        return;
    }

    for(int y=x+1; y<n; y++) {
        if(chk[y]) continue;
        chk[y] = true;
        dfs(x+1, pick+2, ans+v[x][y]);
        chk[y] = false;
        dfs(x+1, pick, ans);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
            if(i>j) {
                v[j][i]+=v[i][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j<=i; j++) {
            printf("  ");
        }
        for(int j=i+1; j<n; j++) {
            printf("%d ", v[i][j]);
        }
        puts("");
    }

    chk[0] = true;
    dfs(0,0,0);
    printf("%d", mn);
    return 0;
}
