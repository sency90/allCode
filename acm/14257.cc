#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;
typedef bitset<40> b40;
int main() {
    ll s,x;
    scanf("%lld%lld",&s,&x);
    if((s-x)%2) return 0&puts("0");
    ll nd = (s-x)>>1;
    b40 a(x), b(nd);
    ll ret = 1LL;
    for(int i=0; i<40 ;i++) {
        if(a[i]==1 && b[i]==0) ret<<=1;
        else if(a[i]==1 && b[i]==1) ret=0;
    }
    if(!nd) ret-=2;
    printf("%lld", ret);
    return 0;
}

