#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> ans,v[1001];
int in[1001];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int cnt; scanf("%d",&cnt);
        for(int j=0; j<cnt; j++) {
            int pd,d; scanf("%d",&d);
            if(j) {
                v[pd].push_back(d);
                in[d]++;
            }
            pd=d;
        }
    }
    for(int i=1; i<=n; i++) if(!in[i]) q.push(i);
    for(int i=0; i<=n; i++) {
        if(q.empty()) break;
        int x=q.front(); q.pop();
        ans.push_back(x);
        for(int y: v[x]) {
            if(--in[y]==0) q.push(y);
        }
    }
    if(ans.size() != n) puts("0");
    else for(int p: ans) printf("%d\n",p);
    return 0;
}
