#include <cstdio>
using namespace std;
long long gcd(long long x, long long y) {
    return y==0LL?x:gcd(y,x%y);
}
long long f(long long x, long long y) {
    long long tmp = gcd(x,y);
    return (x/tmp)*y;
}
int main() {
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long x,y,lcm=f(n,m);
    for(int i=0; i<k; i++) {
        scanf("%lld%lld",&x,&y);
        if((x+y)&1LL) {
            puts("-1");
            continue;
        }
        long long s=0LL;
        for(long long j=0LL;j<=m;j++) {
            if(j&1LL) {
                s=(j+1LL)*n-x;
            } else {
                s=j*n+x;
            }
            if(s>lcm) {
                puts("-1");
                break;
            }
            long long a=s/m, b=s%m;
            if(a&1LL) {
                if(m-b==y) {
                    printf("%lld\n",s);
                    break;
                }
            } else {
                if(b==y) {
                    printf("%lld\n",s);
                    break;
                }
            }
        }
    }
    return 0;
}
