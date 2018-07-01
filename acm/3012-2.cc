#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[201];
const ll MOD = 1e5;
ll dpClose[201][201], dpOpen[201][201];
inline int getCnt(int l, int r) {
    if(l>=r) return 0;
    if(s[l]=='?' && s[r]=='?') return 3;
    if(s[l]=='[' && s[r]==']') return 1;
    if(s[l]=='(' && s[r]==')') return 1;
    if(s[l]=='{' && s[r]=='}') return 1;
    if(s[l]=='?' && (s[r]==')'||s[r]==']'||s[r]=='}')) return 1;
    if(s[r]=='?' && (s[l]=='('||s[l]=='['||s[l]=='{')) return 1;
    return 0;
}
ll getOpen(int l, int r);
ll getClose(int l, int r) {
    ll &ret = dpClose[l][r];
    if(ret>=0) return ret;
    else ret=0;

    if(l>r) return ret=1;
    if(l==r) return ret=0;
    if(l+1==r) return ret=getCnt(l,r);
    ret = getCnt(l,r) * (getClose(l+1,r-1) + getOpen(l+1,r-1)) % MOD;
    return ret;
}
ll getOpen(int l, int r) {
    ll &ret = dpOpen[l][r];
    if(ret>=0) return ret;
    else ret=0;
    if(r < l+3) return ret=0;

    if(l>r) return ret=0;
    if(l==r) return ret=0;
    for(int i=l+1; i<r; i+=2) {
        //ll tmp = getClose(l,i)*((i+2==r)?getClose(i+1,r):getOpen(i+1,r));
        ll tmp = getClose(l,i)*getOpen(i+1,r) % MOD;
        if(tmp>0) {
            //break를 걸지 않아도 이 if문 안에 들어오는 값은 오직 하나뿐
            ret=tmp;
            break;
        }
    }
    for(int i=l+1; i<r; i+=2) {
        ret += getClose(l,i)*getClose(i+1,r);
        ret %= MOD;
    }
    return ret;
}
int main() {
    memset(dpClose, -1, sizeof(dpClose));
    memset(dpOpen, -1, sizeof(dpOpen));
    int n; scanf("%d", &n);
    scanf("%s", s);

    printf("%lld\n", (getClose(0,n-1) + getOpen(0,n-1))%MOD);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%2lld ", dpClose[i][j]);
        }
        puts("");
    }

    puts("");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%2lld ", dpOpen[i][j]);
        }
        puts("");
    }
    return 0;
}
