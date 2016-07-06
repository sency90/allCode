#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[100001];
int mx=0, mx_idx;
bool chk[100001];
void dfs(int x, int sum) {
    chk[x] = true;
    if(mx < sum) {
        mx = sum;
        mx_idx = x;
    }
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i]]) continue;
        chk[v[x][i]] = true;
        dfs(v[x][i], sum+1);
    }
}
int main() {
    int n,x,y;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    memset(chk, false, sizeof(chk));
    dfs(mx_idx, 0);
    if(mx%2==0) printf("%d", mx/2);
    else printf("%d", mx/2+1);
    return 0;
}
