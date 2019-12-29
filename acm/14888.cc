#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
int a[11], opcnt[11];
int n, mn=0x3f3f3f3f, mx=-0x3f3f3f3f;
set<int> s;
void dfs(int x, int pick, int res) {
    if(pick==n-1) {
        mn = min(mn, res);
        mx = max(mx, res);
        return;
    }

    for(int i=0; i<4; i++) {
        if(opcnt[i]) {
            opcnt[i]--;
            if(i==0) dfs(x+1, pick+1, res+a[x+1]);
            else if(i==1) dfs(x+1, pick+1, res-a[x+1]);
            else if(i==2) dfs(x+1, pick+1, res*a[x+1]);
            else dfs(x+1, pick+1, res/a[x+1]);
            opcnt[i]++;
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<4; i++) scanf("%d", &opcnt[i]);
    dfs(0,0,a[0]);
    printf("%d\n%d\n",mx,mn);
    return 0;
}
