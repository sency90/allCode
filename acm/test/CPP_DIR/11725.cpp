#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[100001];
bool chk[100001];
int paren[100001];
void dfs(int x) {
    chk[x] = true;
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i]]) continue;
        dfs(v[x][i]);
        paren[v[x][i]] = x;
    }
}
int main() {
    memset(chk, false, sizeof(chk));
    int n, a, b;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=2; i<=n; i++) {
        printf("%d\n", paren[i]);
    }
    return 0;
}
