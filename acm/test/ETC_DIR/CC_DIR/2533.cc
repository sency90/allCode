#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[1000001];
bool chk[1000001];
int cnt=0;
void dfs(int x, int r) {
    bool haveToChk = false;
    for(int y: v[x]) {
        if(y^r) {
            dfs(y,x);
            haveToChk |= !chk[y];
        }
    }
    if(haveToChk) chk[x]=true,cnt++;
}
int main() {
    int n; scanf("%d",&n);
    for(int i=1; i<n; i++) {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    printf("%d",cnt);
    return 0;
}
