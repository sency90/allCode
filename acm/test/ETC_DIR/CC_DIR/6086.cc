#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[52];
int r[52][52],src,sink,ans;
bool chk[52];
int chg(char x) {
    if(isupper(x)) return x-'A'+26;
    else return x-'a';
}
int dfs(int s, int mn) {
    if(chk[s]) return 0;
    chk[s] = true;
    if(s==sink) return mn;
    for(auto &p : v[s]) {
        if(chk[p]) continue;
        if(r[s][p] <= 0) continue;
        int f = dfs(p, min(mn, r[s][p]));
        r[s][p]-=f; r[p][s]+=f;
        if(f>0) return f;
    }
    return 0;
}
int main() {
    int n,f,s,e;
    char ss[2],ee[2];
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s%s%d",ss,ee,&f);
        s=chg(ss[0]); e=chg(ee[0]);
        if(!r[s][e] && !r[e][s]) {
            v[s].emplace_back(e);
            v[e].emplace_back(s);
        } r[s][e] += f;
    }
    const int inf = 0x3f3f3f3f;
    src = chg('A'), sink = chg('Z'), ans=0;
    while(true) {
        memset(chk, false, sizeof(chk));
        f = dfs(src, inf);
        ans += f;
        if(f == 0) break;
    }
    printf("%d",ans);
    return 0;
}
