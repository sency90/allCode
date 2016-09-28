#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned int bit;
bit broken;
int ABS(int x) { return x<0?-x:x; }
struct Bit{
    int v[10], dn, orival;
    int val() { return orival; }
    Bit():dn(1),orival(0) { memset(v,0,sizeof(v)); }
    Bit* inc() {
        orival++;
        v[0]++;
        for(int i=0; i<dn; i++) {
            if(v[i]==10) {
                v[i+1]++;
                v[i]=0;
            } else break;
        }
        getdn();
        return this;
    }
    bool isBroken() {
        for(int i=0; i<dn; i++) {
            if((1<<v[i])&broken) return true;
        }
        if(v[dn]==0) return false;
        else if((1<<v[dn])&broken) return true;
        return false;
    }
    int getdn() {
        if(v[dn]==0) return dn;
        else return ++dn;
    }
};
int main() {
    int n,m,d;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        broken|=(1<<d);
    }
    int mx=ABS(n-100),mn=0x3f3f3f3f;
    if(broken==((1<<11)-1)) {
        printf("%d\n", mx);
        return 0;
    }
    for(Bit cur; cur.val()<999900; cur.inc()) {
        if(cur.isBroken()) continue;
        mn = min(mn, cur.getdn()+ABS(n-cur.val()));
    }
    printf("%d\n", min(mx,mn));
    return 0;
}
