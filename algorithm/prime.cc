#include <stdio.h>
bool isPrime(int n) {
    if(n<=1) return false;
    else if(n==2) return true;
    else if(n%2 == 0) return false;
    else {
        for(int i=3; i*i<=n; i+=2) {
            if(n%i == 0) return false;
        }
        return true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if(isPrime(n)) printf("%d is a prime\n",n);
    else printf("%d isn't a prime\n", n);
    return 0;
}
