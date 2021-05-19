#include <stdio.h>
#include <string.h>
int main() {
    bool isPrime[1001];
    memset(isPrime, true, sizeof(isPrime));
    int n, d, cnt=0; scanf("%d", &n);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i*i<=1000; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=1000; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        if(isPrime[d]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
