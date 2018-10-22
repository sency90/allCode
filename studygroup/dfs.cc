#include <cstdio>
#include <vector>
using namespace std;
bool chk[6];
vector<int> v;
int n;
void dfs(int x) {
    if(x==0) {
        for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
        puts("");
        return;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        chk[i] = true;
        v.push_back(i);
        dfs(x-1);
        v.pop_back();
        chk[i] = false;
    }
}
int main() {
    scanf("%d", &n);
    dfs(n);
    return 0;
}
