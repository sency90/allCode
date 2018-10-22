#include <cstdio>
#include <vector>
using namespace std;
int n, r;
vector<int> v;
void dfs(int r, int x) {
    if(r==0) {
        for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
        puts("");
        return;
    }

    for(int i=x+1; i<=n; i++) {
        v.push_back(i);
        dfs(r-1, i);
        v.pop_back();
    }
}
int main() {
    scanf("%d %d", &n,&r);
    dfs(r,0);
    return 0;
}
