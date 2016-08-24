#include <cstdio>
using namespace std;
int main() {
    long long a, tmp=0LL;
    scanf("%lld", &a);
    if(a<3LL) {
        puts("-1");
        return 0;
    }
    if(a%4LL == 0LL) {
        long long tmp = a/4LL;
        printf("%lld %lld", 3*tmp, 5*tmp);
        return 0;
    }
    long long i;
    for(i=3LL; i*i<=a; i++) {
        if(a%i == 0LL) {
            tmp = a/i;
            break;
        }
    }
    if(a%i == 0LL) tmp = a/i;
    if(tmp>0) {
        long long x = a/tmp;
        long long ans = (x*x-1LL)/2LL;
        printf("%lld %lld", ans*tmp, (ans+1LL)*tmp);
    } else {
        long long ans = (a*a-1LL)/2LL;
        printf("%lld %lld", ans, ans+1LL);
    }
    return 0;
}
