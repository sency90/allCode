#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
bool chk[52];
int r[52][52];
int chg(char c) {
    if(islower(c)) return c-'a'+26;
    else return c-'A';
}
int src,sink,f;
int dfs(int x, int mnf) {
    if(chk[x]) return 0;
    chk[x]=true;
    if(x==sink) return mnf;
    for(int i=1; i<=51; i++) {
        if(!chk[i] && r[x][i]>0) {
            int f = dfs(i, min(mnf, r[x][i]));
            if(f) {
                r[x][i] -= f;
                r[i][x] += f;
                return f;
            }
        }
    }
    return 0;
}
int flow() {
    int ans=0,f;
    while(true) {
        memset(chk, false, sizeof(chk));
        f=dfs(src, 0x3f3f3f3f);
        if(f==0) break;
        ans+=f;
    }
    return ans;
}
int main() {
    char s[2],e[2];
    int n,f,ss,ee;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s%s%d",s,e,&f);
        ss = chg(s[0]), ee = chg(e[0]);
        r[ss][ee]+=f;
    }
    src = chg('A'); sink = chg('Z');
    printf("%d", flow());
    return 0;
}
