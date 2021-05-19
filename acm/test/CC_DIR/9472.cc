#include <cstdio>
using namespace std;
typedef long long ll;
ll d[18],c[18][18];
ll f(int n) {
    if(n<=1) return n^1;
    if(d[n]>0) return d[n];
    return d[n]=(n-1)*(f(n-1)+f(n-2));
}
ll co(int n, int k) {
    if(n==k||k==0) return 1LL;
    if(c[n][k]>0) return c[n][k];
    return c[n][k]=co(n-1,k-1)+co(n-1,k);
}
int main() {
    int tc,no,n,k; scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d%d",&no,&n,&k);
        ll ans=f(n);
        for(int i=n-k-1,z=0; i>=0; i--,z++) {
            for(int j=0; j<=i; j++) {
                ans += f(k+j+z)*co(i,j);
            }
        }
        printf("%d %lld\n",no,ans);
    }
    return 0;
}
