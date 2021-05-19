#include <stdio.h>
static long long cntzero = 0;
static long long cntone = 0;
long long fibo[41][2];
bool hasFibo[41];

int fibonacci(int n) {
    if( n == 0 ) {
        hasFibo[0] = true;
        cntzero++;
    } else if (n == 1) {
        hasFibo[1] = true;
        cntone++;
    } else {
        if(!hasFibo[n-1]) {
            fibonacci(n-1);
            fibo[n-1][0] = cntzero;
            fibo[n-1][1] = cntone;
            hasFibo[n-1] = true;
        } else {
            cntzero += fibo[n-1][0];
            cntone += fibo[n-1][1];
        }

        if(!hasFibo[n-2]) {
            fibonacci(n-2);
            fibo[n-2][0] = cntzero;
            fibo[n-2][1] = cntone;
            hasFibo[n-2] = true;
        } else {
            cntzero += fibo[n-2][0];
            cntone += fibo[n-2][1];
        }
    }
    return 0;
}

int main() {
    int T, N;
    scanf("%d", &T);

    for(int i=0; i<41; i++) {
        hasFibo[i] = false;
    }

    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;

    for(int i=0; i<T; i++) {
        scanf("%d", &N);
        fibonacci(N);
        printf("%llu %llu\n", cntzero, cntone);
        cntzero = 0;
        cntone = 0;
    }
    return 0;
}
