#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100001];
int n, cnt=1;
bool valid(int x) {
    return (x>=0)&&x<n;
}
bool chk[100001];
void dfs(int x) {
    chk[x]=true;
    for(int y: v[x]) {
        if(chk[y]) continue;
        chk[y]=true;
        cnt++;
        dfs(y);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(valid(i-x)) v[i].push_back(i-x);
        if(valid(i+x)) v[i].push_back(i+x);
    }
    int k; scanf("%d", &k);
    dfs(k-1);
    printf("%d", cnt);
    return 0;
}
