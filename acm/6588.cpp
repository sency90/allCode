#include <stdio.h>
#include <string.h>
#define N 1000000
int main() {
    bool isP[N+1];
    int k = 0, d, prime[78500];
    memset(isP, true, sizeof(isP));
    memset(prime, 0, sizeof(prime));
    long long i, j;
    isP[0] = false;
    isP[1] = false;
    for(i=2; i<=N; i++) {
        if(isP[i]) {
            prime[k++] = i;
            for(j=i*i; j<=N; j+=i) {
                isP[j] = false;
            }
        }
    }

    isP[2] = false;
    while(true) {
        scanf("%d", &d);
        if(d == 0) return 0;
        for(i=1; true; i++) {
            if(d-prime[i]<0) {
                printf("Goldbach's conjecture is wrong\n");
                break;
            }
            if(isP[d-prime[i]]) {
                printf("%d = %d + %d\n", d, prime[i], d-prime[i]);
                break;
            }
        }
    }
    return 0;
}
