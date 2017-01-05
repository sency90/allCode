#include <cstdio>
using namespace std;
typedef unsigned long long ull;
bool isPrime(ull n) {
    if(n<=1ULL) return false;
    else if(n==2ULL) return true;
    else if(n%2ULL == 0) return false;
    else {
        for(ull i=3ULL; i*i<=n; i+=2ULL) {
            if(n%i == 0ULL) return false;
        }
        return true;
    }
}
int main() {
    ull n; scanf("%llu", &n);
    if(isPrime(n)) printf("%llu is a prime\n",n);
    else printf("%llu isn't a prime\n", n);
    return 0;
}
