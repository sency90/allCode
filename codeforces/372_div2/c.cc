#include <cstdio>
using namespace std;
int main() {
    long long n,s=2LL;
    scanf("%lld", &n);
    for(long long i=1LL; i<=n; i++) {
        printf("%lld\n", i*(i+1)*(i+1)-s/i);
        s = i*(i+1);
    }
    return 0;
}
