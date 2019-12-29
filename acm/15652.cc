#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v;
int n,m;
void dfs(int x) {
    if(v.size()==m) {
        for(int i=0; i<v.size(); i++) {
            printf("%d ", v[i]);
        }
        puts("");
        return;
    }

    for(int i=x?x:x+1; i<=n; i++) {
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }
}
int main() {
    scanf("%d%d",&n,&m);
    dfs(0);
    return 0;
}
