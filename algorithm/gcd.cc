#include <cstdio>
using namespace std;
long long gcd(long long b, long long s) { return s?gcd(s,b%s):b; }
int main() {
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",gcd(x,y));
    return 0;
}
