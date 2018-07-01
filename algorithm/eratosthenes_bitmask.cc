#include <stdio.h>
#include <cstring>
using namespace std;
#define TOTAL (1ULL<<23)
typedef unsigned long long ull;
typedef unsigned int uint;
char prime[(TOTAL+7U)>>3];
bool isPrime(unsigned int k) {
    return prime[k>>3] & (1U<<(k&7));
}
void setComposite(unsigned int k) {
    prime[k>>3] &= ~(1U<<(k&7));
}
int main() {
    ull n=TOTAL;
    memset(prime, 0xff, sizeof(prime));
    setComposite(0); setComposite(1);
    for(ull i=2ULL; i*i<=n; i++) {
        if(isPrime(i)) {
            for(ull j=i*i; j<=n; j+=i) {
                setComposite(j);
            }
        }
    }
    int d;
    while(true) {
        scanf("%d", &d);
        if(d<=0) return 0;
        if(isPrime(d)) printf("%d is a prime.\n",d);
        else printf("%d is not a prime.\n",d);
    }
    return 0;
}
