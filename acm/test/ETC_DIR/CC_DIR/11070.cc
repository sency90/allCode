#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long w[1001], l[1001];
int main() {
    int tc,n,m,a,b;
    long long p,q;
    scanf("%d", &tc);
    while(tc--) {
        memset(w, 0, sizeof(w));
        memset(l, 0, sizeof(l));
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            scanf("%d%d%lld%lld",&a,&b,&p,&q);
            w[a]+=p; l[a]+=q;
            w[b]+=q; l[b]+=p;
        }
        long long mx=0LL, mn=0x3f3f3f3fLL;
        for(int i=1; i<=n; i++) {
            if(w[i]==0LL && l[i]==0LL) mn=0LL;
            else {
                long long tmp = w[i]*w[i]*1000LL/(w[i]*w[i]+l[i]*l[i]);
                if(mx<tmp) mx=tmp;
                if(mn>tmp) mn=tmp;
            }
        }
        printf("%lld\n%lld\n",mx,mn);
    }
    return 0;
}
