#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7LL;
int n;
string s;
ll d[101][101];
ll f(int x, int oCnt) {
    ll &ret = d[x][oCnt];
    if(ret!=-1) return ret;
    else ret = 0;

    if(oCnt==0) ret = 1;

    int pos=x+1;
    for(; pos<s.size(); pos++) if(s[pos]=='(') break;
    if(pos<s.size()) ret += f(pos, oCnt+1);

    if(oCnt>0) {
        pos=x+1;
        for(; pos<s.size(); pos++) if(s[pos]==')') break;
        if(pos<s.size()) ret += f(pos, oCnt-1);
    }

    return ret%=mod;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    s = " "+s;
    memset(d, -1, sizeof(d));
    printf("%lld", f(0,0)-1);
    return 0;
}
