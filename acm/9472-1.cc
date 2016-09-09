#include <cstdio>
using namespace std;
typedef long long ll;
ll d[18], c[18][18];
ll f(int x) {
    if(x<=1) return x^1;
    if(d[x]>0LL) return d[x];
    return d[x] = (x-1)*(f(x-1)+f(x-2));
}
ll combi(int n, int r) {
    if(n==r||r==0) return 1LL;
    if(c[n][r]>0) return c[n][r];
    return c[n][r] = combi(n-1,r-1)+combi(n-1,r);
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int no,n,k;
        scanf("%d%d%d",&no,&n,&k);
        if(k>n) { puts("0"); return 0; }
        ll ans = 0LL;
        for(int i=0; i<=n-k; i++) ans += f(k+i)*combi(n-k,i);
        printf("%d %lld\n", no, ans);
    }
    return 0;
}
