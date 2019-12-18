#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int m;
vector<int> v;
bool chk[101];
int ans=-1;
void dfs(vector<int> & idx) {
    if(idx.size()==3) {
        int r=0;
        for(int i=0; i<idx.size(); i++) r+=v[idx[i]];
        if(r<=m) ans=max(ans,r);
        return;
    }
    for(int i=0; i<v.size(); i++) {
        if(!chk[i]) {
            chk[i] = true;
            idx.push_back(i);
            dfs(idx);
            idx.pop_back();
            chk[i] = false;
        }
    }
}
int main() {
    int n; scanf("%d%d",&n,&m);
    for(int i=0; i<n ;i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    vector<int> idx;
    dfs(idx);
    printf("%d\n", ans);
    return 0;
}
