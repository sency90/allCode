#include <cstdio>
using namespace std;
int main() {
    long long r,c,n;
    scanf("%lld%lld%lld",&r,&c,&n);
    printf("%lld\n",(long long)((r+(n-1LL))/n)*(long long)((c+(n-1LL))/n));
    return 0;
}
