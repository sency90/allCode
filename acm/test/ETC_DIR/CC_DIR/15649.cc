#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, m;
void go(int x, int cnt, vector<int> &v, vector<bool> &chk) {
    v.push_back(x);
    chk[x] = true;
    if(cnt==m) {
        for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
        puts("");
        v.pop_back();
        chk[x] = false;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        go(i, cnt+1, v, chk);
    }
    v.pop_back();
    chk[x] = false;
}
vector<int> v;
vector<bool> chk(9);
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        go(i,1,v,chk);
    }
    return 0;
}
