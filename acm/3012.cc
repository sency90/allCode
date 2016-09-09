#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const long long MOD = 1e5;
long long d[200][200];
char open[]={"[{("}, close[]={"]})"}, s[201];
int isPair(int l, int r) {
    if(s[l]=='?'&&s[r]=='?') return 3;
    else if(s[l]=='?') {
        for(int i=0; i<3; i++) if(s[r]==close[i]) return 1;
    } else if(s[r]=='?') {
        for(int i=0; i<3; i++) if(s[l]==open[i]) return 1;
    } else {
        for(int i=0; i<3; i++) {
            if(s[l]==open[i] && s[r]==close[i]) return 1;
        }
    }
    return 0;
}
bool isOver = false;
long long f(int l, int r) {
    if(l>r) return 1LL;

    long long &ret = d[l][r];
    if(ret!=-1LL) return ret;
    else ret=0LL;

    int cnt;
    for(int k=l+1; k<=r; k+=2) {
        if((cnt=isPair(l,k)) > 0) {
            ret += f(l+1,k-1)*f(k+1,r)*cnt;
            if(ret>=MOD) {
                isOver = true;
                ret%=MOD;
            }
        }
    }
    return ret;
}
int main() {
    int n;
    scanf("%d%s", &n,s);
    memset(d, -1, sizeof(d));
    if(strlen(s)&1) puts("0");
    else {
        long long ans = f(0,n-1);
        if(isOver) printf("%05lld", ans);
        else printf("%lld", ans);
    }
    return 0;
}
