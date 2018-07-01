#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long ll;
bool isPrime[100001];
int main() {
    ll n; scanf("%lld", &n);
    assert(1<=n && n<=100000);

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;

    for(ll i=2; i*i<=n; i++) {
        if(!isPrime[i]) continue;
        for(ll j=i*i; j<=n; j+=i) {
            isPrime[j]=false;
        }
    }

    int primeCnt=0;
    for(int i=1; i<=n; i++) {
        if(isPrime[i]) primeCnt++;
    }
    printf("prime count [1,%lld]: %d\n", n,primeCnt);
    return 0;
}
