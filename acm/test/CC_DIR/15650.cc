#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<int> ans;
int n, m;
void dfs(int x, int cnt, vector<int> &ans) {
    if(cnt>=m) {
        if(cnt==m) {
            for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
            puts("");
        }
        return;
    }
    for(int j=0; j<v[x].size(); j++) {
        int y = v[x][j];
        ans.push_back(y);
        dfs(y, cnt+1, ans);
        ans.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    v.clear();
    v.resize(n+1, vector<int>());
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            v[i].push_back(j);
        }
    }

    for(int i=1; i<=n; i++) {
        ans.push_back(i);
        dfs(i, 1, ans);
        ans.pop_back();
    }
    return 0;
}
