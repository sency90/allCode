#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> mnh;
vector<int> v[32001], ans;
int in[32001];
int main() {
    int n,m; scanf("%d%d", &n,&m);
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        in[b]++;
    }
    for(int i=1; i<=n; i++) {
        if(!in[i]) mnh.push(-i);
    }
    while(!mnh.empty()) {
        int x = -mnh.top(); mnh.pop();
        ans.push_back(x);
        for(int y: v[x]) {
            if(--in[y]==0) mnh.push(-y);
        }
    }
    for(int y: ans) printf("%d ", y);
    return 0;
}
