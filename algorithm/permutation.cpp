#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
bool chk[11];
int v[11];
int n;
int anscnt=0;
void dfs(int x, vector<int>& ans) {
    chk[x] = true;
    if(ans.size()==n) {
        for(int i=0; i<n; i++) {
            printf("%d ", ans[i]);
        }
        anscnt++;
        puts("");
    } else {
        for(int i=1; i<=n; i++) {
            if(!chk[i]) {
                ans.push_back(v[i]);
                dfs(i, ans);
                ans.pop_back();
            }
        }
    }
    chk[x] = false;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    vector<int> ans;
    dfs(0,ans);
    printf("cnt: %d\n", anscnt);
    return 0;
}
