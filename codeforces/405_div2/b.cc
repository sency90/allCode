#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[150001];
int chk[150001], cnt;
bool ans=true;
stack<int> s;
void dfs(int x) {
    chk[x]=true;
    s.push(x);
    cnt++;
    for(int y: v[x]) {
        if(chk[y]) continue;
        else dfs(y);
    }
}
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    int a,b;
    for(int i=0; i<k; i++) {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++) {
        if(chk[i]) continue;
        else {
            cnt=0;
            dfs(i);
            while(!s.empty()) {
                int x=s.top(); s.pop();
                if(v[x].size()!=cnt-1) return 0&puts("NO");
            }
        }
    }
    puts("YES");
    return 0;
}
