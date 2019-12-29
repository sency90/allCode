#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
bool chk[9];
void dfs(int x) {
    if(v.size() == m) {
        for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
        puts("");
        return;
    }

    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        chk[i] = true;
        v.push_back(i);
        dfs(i);
        v.pop_back();
        chk[i] = false;
    }
}
int main() {
    scanf("%d%d",&n,&m);
    dfs(0);
    return 0;
}
