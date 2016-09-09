#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SMALL=1, BIG=0;
typedef long long ll;
ll d[82][82][2];
int v[82];
char s[81];
ll f(int n, int last, int sm) {
    if(n==0) {
        if(sm) return 1LL;
        else return 0LL;
    } else if(last==0) return 1LL;
    ll &ret = d[n][last][sm];
    if(ret!=-1) return ret;
    else ret=0LL;

    int lim = min(v[n],last);
    for(int i=0; i<lim; i++) ret += f(n-1,i,SMALL);
    ret+=f(n-1,lim,sm);
    for(int i=lim+1; i<=last; i++) ret += f(n-1,i,BIG);
    return ret;
}
int main() {
    int tc; scanf("%d",&tc);
    while(tc--) {
        scanf("%s", s);
        memset(d, -1, sizeof(d));
        int n = strlen(s);
        bool hasAns=true;
        for(int i=0; i<n; i++) {
            v[i+1]=s[i]-'0';
            if(v[i+1]<v[i]) { hasAns=false; break; }
        }
        if(!hasAns) { puts("-1"); continue; }
        printf("%lld\n", f(n,9,SMALL)-1LL);
    }
    return 0;
}
