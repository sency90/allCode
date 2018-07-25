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
    int cnt=0;
    for(int i=923456; i<990000; i++) {
        if(isPrime(i)) {
            printf("%d\n", i);
            cnt++;
        }
        if(cnt>=20) break;
    }
    return 0;
}
