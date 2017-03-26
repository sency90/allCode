#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1001],c[26],n,mx=1;
const int MOD = 1e9+7, inf=0x3f3f3f3f;
char s[1002];
inline void mod(int &x) {
    if(x>=MOD) x%=MOD;
}
int f(int x) {
    if(x==n) return 1;
    if(d[x]>=0) return d[x];
    else d[x]=0;

    int cnt[26], mn=inf, j=1;
    memset(cnt,0,sizeof(cnt));
    for(int i=x; i<n; i++, j++) {
        mn=min(c[s[i]-'a'],mn);
        if(j > mn) break;
        mx=max(j,mx);
        d[x]+=f(i+1);
        mod(d[x]);
    }
    return d[x];
}
int mncnt=0;
void dfs(int x) {
    if(x==n) return;
    mncnt++;
    int cnt[26], j=1, mn=inf;
    memset(cnt,0,sizeof(cnt));
    for(int i=x; i<n; i++, j++) {
        mn=min(c[s[i]-'a'],mn);
        if(j>mn) break;
    }
    dfs(x+j-1);
}
int main() {
    memset(d,-1,sizeof(d));
    scanf("%d", &n);
    scanf("%s", s);
    for(int i=0; i<26; i++) {
        scanf("%d", &c[i]);
    }

    int ans1=f(0);
    printf("%d\n", ans1);
    printf("%d\n", mx);
    dfs(0);
    printf("%d\n", mncnt);
    return 0;
}
