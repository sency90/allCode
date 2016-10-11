#include <cstdio>
#include <vector>
using namespace std;
bool isPrime[1001];
vector<int> prime;
int main() {
    int n;
    isPrime[0]=isPrime[1]=true;
    for(int i=2; i<=1000; i++) {
        if(isPrime[i]) continue;
        for(int j=i*i; j<=1000; j+=i) {
            isPrime[j]=true;
        }
    }
    for(int i=0; i<=1000; i++) {
        isPrime[i]=!isPrime[i];
        if(isPrime[i]) prime.push_back(i);
    }
    scanf("%d", &n);
    if(n&1) {
        for(auto &p : prime) {
            for(auto &q : prime) {
                if(n-p-q<=1) continue;
                if(isPrime[n-p-q]) {
                    printf("%d %d %d", p,q,n-p-q);
                    return 0;
                }
            }
        }
    } else puts("0");
    return 0;
}
