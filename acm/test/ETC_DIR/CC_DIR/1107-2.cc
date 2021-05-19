#include <cstdio>
#include <algorithm>
using namespace std;
typedef int bit;
bit broken;
int ABS(int x) { return x<0?-x:x; }
int getdn(int x) {
    int cnt=0;
    while(x!=0) { x/=10; cnt++; }
    return cnt;
}
bool isBroken(int x) {
    while(x!=0) {
        if(broken&(1<<(x%10))) return true;
        x/=10;
    }
    return false;
}
int main() {
    int n, dn;
    scanf("%d", &n);
    dn=getdn(n);

    int m,d;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        broken|=(1<<d);
    }

    int mx=ABS(n-100),mn=0x3f3f3f3f;
    for(int cur=0;;cur++) {
        if(isBroken(cur)) continue;
        mn = min(mn, getdn(cur)+ABS(n-cur));
        if(cur>n) break;
    }
    printf("%d\n", min(mx,mn));
    return 0;
}
