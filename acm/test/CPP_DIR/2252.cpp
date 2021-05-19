#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[32001];
bool chk[32001];
void f(int x) {
    chk[x] = true;
    for(int i=0; i<v[x].size();i++) {
        if(!chk[v[x][i]]) {
            f(v[x][i]);
        }
    }
    printf("%d ", x);
}
int main() {
    memset(chk, false, sizeof(chk));
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        if(!chk[i]) {
            f(i);
        }
    }
    return 0;
}
