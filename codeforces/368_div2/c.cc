#include <cstdio>
#include <cmath>
using namespace std;
bool isPrime(long long n) {
    if(n<=2LL) return false;
    else if(n==3LL) return true;
    else if(n%2LL) return false;
    else {
        for(long long i=2LL; i*i<=n; i++) {
            if(n%i == 0LL) return false;
        }
        return true;
    }
}
int main() {
    long long a;
    scanf("%lld", &a);
    if(a<3LL) {
        puts("-1");
        return 0;
    }
    if(isPrime(a)) {
        long long ans = (a*a-1LL)/2LL;
        printf("%lld %lld",ans,ans+1LL);
    } else {
        long long x = sqrt(2LL*a+1LL);
        if(x*x == 2LL*a+1LL) printf("%lld %lld", x, a+1);
        else {
            x = sqrt(2LL*a-1LL);
            if(x*x == 2LL*a-1LL) printf("%lld %lld",x, a-1);
            else puts("-1");
        }
    }
    return 0;
}

