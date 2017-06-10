#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
int s[110], v[110], tm[110], p[110];
pii d[110];
bool chk[110];
int n,lim;
const int inf = 0x3f3f3f3f;
pii f(int x) {
    if(x==0) return pii(0,0);
    pii &ret = d[x];
    if(chk[x]) return ret;
    chk[x]=true;

    for(int i=1; x-i>=0; i++) {
        if(s[x]-s[x-i]<=lim) {
            pii tmp = f(x-i);
            if(ret.first > tmp.first+tm[x]) {
                ret.first = tmp.first+tm[x];
                ret.second = tmp.second+1;
                p[x]=x-i;
            }
        } else break;
    }
    return ret;
}
int main() {
    memset(p,-1,sizeof(p));
    scanf("%d%d",&lim,&n);
    for(int i=1; i<=n+1; i++) {
        scanf("%d",&v[i]);
        s[i]+=s[i-1]+v[i];
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &tm[i]);
    }
    for(int i=0; i<=n+1; i++) {
        d[i].first=inf;
        d[i].second=0;
    }
    pii ans = f(n+1);
    if(ans.first==0) return 0&puts("0");
    printf("%d\n%d\n", ans.first, ans.second-1);
    stack<int> stk;
    for(int i=p[n+1];i>0;i=p[i]) stk.push(i);
    while(!stk.empty()) { printf("%d ", stk.top()); stk.pop(); }
    return 0;
}

