#include <cstdio>
using namespace std;
typedef long long ll;
static inline void fio(ll *a) {
    register char c=0;
    while(c<33) c=getchar_unlocked();
    *a=0LL;
    while(c>33) {
        *a=*a*10LL+c-'0';
        c=getchar_unlocked();
    }
}
int main() {
    ll i,n,sum=0LL,x;
    fio(&n);
    for(i=0LL; i<n; i++) {
        fio(&x);
        sum+=x;
    }
    printf("%lld\n%lld\n",i,sum);
    return 0;
}
