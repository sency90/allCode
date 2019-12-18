#include <cstdio>
#include <cstring>
using namespace std;
bool prime[1000001];
int main() {
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1] = false;
    for(int i=2; i<=1000; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=1000000; j+=i) {
                prime[j] = false;
            }
        }
    }

    for(int i=1000; i<=1300; i++) {
        if(prime[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}
