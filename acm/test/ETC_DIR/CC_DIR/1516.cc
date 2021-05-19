#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> v[501];
int w[501], in[501], tm[501];
int main() {
    int n,x; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&w[i]);
        while(~scanf("%d",&x)) {
            if(x==-1) break;
            v[x].push_back(i);
            in[i]++;
        }
        if(!in[i]) q.push(i), tm[i]=w[i];
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int y: v[x]) {
            tm[y]=max(tm[y], tm[x]+w[y]);
            if(--in[y]==0) q.push(y);
        }
    }
    for(int i=1; i<=n; i++) printf("%d\n",tm[i]);
    return 0;
}
