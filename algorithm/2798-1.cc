#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[101], ans=-1, n,m;
void dfs(int x, int cnt, int sum) {
    if(x>n || cnt>3) return; //완전히 끝나는 경우
    else if(cnt==3) {
        if(sum <= m) ans = max(ans, sum);
        return;
    }
    else if(x==n) return;

    dfs(x+1, cnt+1, sum+v[x]); //선택을 하는 경우
    dfs(x+1, cnt, sum); //선택을 하지 않는 경우
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    dfs(0, 0, 0);
    printf("%d", ans);
    return 0;
}
