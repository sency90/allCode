#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int,int> > v[10001];
int mx=0, mx_idx;
bool chk[10001];
void dfs(int x, int sum) {
    chk[x] = true;
    if(mx < sum) {
        mx = sum;
        mx_idx = x;
    }
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i].first]) continue;
        chk[v[x][i].first] = true;
        dfs(v[x][i].first, sum+v[x][i].second);
    }
}
int main() {
    int n,p,c,w;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d%d",&p,&c,&w);
        v[p].push_back(make_pair(c,w));
        v[c].push_back(make_pair(p,w));
    }
    dfs(1,0);
    memset(chk, false, sizeof(chk));
    dfs(mx_idx, 0);
    printf("%d", mx);
    return 0;
}
