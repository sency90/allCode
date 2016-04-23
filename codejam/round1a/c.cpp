#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[10];
int dfs(int x) {
    chk[x] = true;
    for()
}
int main() {
    int t, n; scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d", &n);
        for(int j=1; j<=n; j++) {
            scanf("%d", &d);
            v[j].push_back(d);
            v[d].push_back(j);
        }
        printf("Case #%d: ", i);
        for(int j=1; j<=n; j++) {
            dfs(j);
        }
    }
    return 0;
}

