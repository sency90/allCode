#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        q.push(i&1);
    }

    int x = q.front(); q.pop();
    while(!q.empty()) {
        x^=q.front(); q.pop();
    }

    int ans=0;
    if(x&1) {
        for(int i=2; i<=n; i+=2) ans+=i;
    } else {
        for(int i=1; i<=n; i+=2) ans+=i;
    }
    printf("%d", ans);
    return 0;
}
