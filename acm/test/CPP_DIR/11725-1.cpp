#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100001];
queue<int> q;
int ans[100001];
bool chk[100001];
int main() {
    int n, a, b, tmp;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    chk[1] = true;
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        for(int i=0; i<v[tmp].size(); i++) {
            if(chk[v[tmp][i]]) continue;
            chk[v[tmp][i]] = true;
            q.push(v[tmp][i]);
            ans[v[tmp][i]]=tmp;
        }
    }
    for(int i=2; i<=n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
