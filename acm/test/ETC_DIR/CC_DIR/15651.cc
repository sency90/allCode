#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
void dfs(int x) {
    if(v.size()==m) {
        for(int i=0; i<v.size(); i++) {
            printf("%d ", v[i]);
        }
        puts("");
        return;
    }
    for(int i=1; i<=n; i++) {
        v.push_back(i);
        dfs(x);
        v.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    dfs(0);
    return 0;
}
