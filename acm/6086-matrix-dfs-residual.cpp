#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;
bool chk[60];
int c[60][60];
int chg(char c) {
    if(islower(c)) return c-'a'+26;
    else return c-'A';
}
int src, sink;
int dfs(int x, int mnc) {
    if(chk[x]) return 0;
    chk[x]=true;
    if(x==sink) {
        return mnc;
    }
    for(int i=1; i<=53; i++) {
        if(c[x][i] > 0) {
            int f = dfs(i, min(mnc, c[x][i]));
            if(f) {
                c[x][i] -= f; //x->i로 f만큼의 flow를 흘려보냈다는 뜻. 따라서 잔여용량은 c[x][i]-f가 된다.
                c[i][x] += f; //i->x로 f만큼의 flow를 회수할 수 있다는 뜻. 따라서 잔여용량은 c[x][i]+f가 된다.
                return f;
            }
        }
    }
    return 0;
}
int flow() {
    int ans = 0, f;
    while(true) {
        memset(chk, false, sizeof(chk));
        f = dfs(src, 0x3f3f3f3f);
        if(f == 0) break; //더 이상 흘려보낼 수 없다면 그만 흘려보낸다.
        ans += f; //흘려보낸 양을 저장한다.
    }
    return ans;
}

int main() {
    char s[2], e[2];
    int n,f;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s %s %d",s,e,&f);
        int ss = chg(s[0]), ee = chg(e[0]);
        c[ss][ee] += f;
        c[ee][ss] += f;
    }
    src = chg('A');
    sink = chg('Z');
    printf("%d", flow());
    return 0;
}
