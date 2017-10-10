#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", x);
        v.push_back(x);
    }
    int s=1, e=10;
    chk[s];
    q.push(s);
    while(!q.empty()) {
        int x=q.front(); q.pop();
        for(int y: v[x]) {
            if(chk[y]) continue;
            chk[y]=true;
            q.push(y);
        }
    }
    return 0;
}
