#include <stdio.h>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> v[53];
bool chk[53];
int r[53][53], src, sink;

int change(char r) {
    if(isupper(r)) return r-'A';
    else return r-'a'+26;
}
int dfs(int x, int mn) {
    if(chk[x]) return 0;
    chk[x] = true;

    if(x==sink) return mn;
    for(auto &y: v[x]) {
        if(chk[y] || r[x][y]<=0) continue;
        int f = dfs(y, min(mn, r[x][y]));
        r[x][y] -= f; r[y][x] += f;
        if(f>0) return f;
    }
    return 0;
}
int main() {
    char s[2], e[2];
    int n,f,ss,ee;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s %s %d",s,e,&f);
        ss = change(s[0]); ee = change(e[0]);
        if(!r[ss][ee]) v[ss].push_back(ee);
        if(!r[ee][ss]) v[ee].push_back(ss);
        r[ss][ee] += f;
    }

    int ans=0;
    src=change('A'); sink=change('Z');
    while(true) {
        memset(chk, false, sizeof(chk));
        int flow = dfs(src, inf);
        if(flow==0) break;
        ans += flow;
    }
    printf("%d", ans);
    return 0;
}
