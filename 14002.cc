#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ans;
int v[1001];
int p[1002];
int d[1001][1002];
bool chk[1001][1002];
int f(int x, int y) {
    if(x==0) return 0;
    int &ret = d[x][y];
    if(chk[x][y]) return ret;
    else chk[x][y] = true;

    ret = f(x-1,y);
    if(y>v[x]) {
        int pret = ret;
        ret = max(ret, f(x-1, v[x])+1);
        if(ret != pret) p[y] = v[x];
    }
    if(y>v[x]) ret = max(f(x-1,y), f(x-1, v[x])+1);
    else ret = f(x-1,y);
    return ret;
}
int main() {
    memset(p,-1,sizeof(p));
    memset(d, 0x3f, sizeof(d));
    int n; scanf("%d", &n);
    int mx = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        mx = max(mx, v[i]);
    }
    mx++;
    printf("%d\n",f(n,mx));

    mx = p[mx];
    while(mx!=-1) {
        ans.push_back(mx);
        mx = p[mx];
    }
    for(int i=ans.size()-1; i>=0; i--) {
        printf("%d ", ans[i]);
    }
    return 0;
}
