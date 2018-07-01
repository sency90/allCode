#include <cstdio>
#include <cstring>
using namespace std;
bool isPrime[100001];
int main() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<=100001; i++) {
        if(!isPrime[i]) continue;
        for(int j=i*2; j<=100001; j+=i) {
            isPrime[j] = false;
        }
    }
    return 0;
}
