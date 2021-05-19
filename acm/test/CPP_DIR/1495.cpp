#include <stdio.h>
#include <cstring>
using namespace std;
int n, s, m;
bool chk[101][1001];
int v[101];
void f(int x, int y) {
    if(chk[x][y]) return;
    chk[x][y] = true;
    if(x==n) return;
    if(y+v[x+1] <= m) f(x+1, y+v[x+1]);
    if(y-v[x+1] >= 0) f(x+1, y-v[x+1]);
}
int main() {
    memset(chk, false, sizeof(chk));
    scanf("%d %d %d", &n, &s, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    f(0, s);
    for(int i=m; i>=0; i--) {
        if(chk[n][i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
