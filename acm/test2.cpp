#include <cstdio>

#define MAX_N 100
#define MOD 1000000000

typedef unsigned long long ULL;
ULL d[MAX_N][10][4];

void proc(int N) {
    // set initial data (i==0)
    for (int k = 0; k < 4; k++)
        d[0][0][k] = 0; // can't start from zero
    for (int j = 1; j < 10; j++) {
        for (int k = 0; k < 4; k++)
            d[0][j][k] = (k==0) ? 1 : 0;
    }
    d[0][9][2] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                d[i][j][1] = (d[i - 1][j + 1][0] + d[i - 1][j + 1][1]) % MOD;
                d[i][j][3] = (d[i - 1][j + 1][2] + d[i - 1][j + 1][3]) % MOD;
            }
            else if (j == 9) {
                d[i][j][2] = (d[i - 1][j - 1][0] + d[i - 1][j - 1][2]) % MOD;
                d[i][j][3] = (d[i - 1][j - 1][1] + d[i - 1][j - 1][3]) % MOD;
            }
            else {
                for (int k = 0; k < 4; k++)
                    d[i][j][k] = (d[i - 1][j - 1][k] + d[i - 1][j + 1][k]) % MOD;
            }
        }
        // printf("%d -> mask= %llx %llx %llx\n", i, d[i][0][1], d[i][0][2], d[i][0][3]);
    }

    ULL sum = 0;
    for (int j = 0; j < 10; j++) {
        // printf("d[%d] = %llx\n", j, d[N - 1][j][3]);
        sum += d[N - 1][j][3];
    }
    printf("%llu\n", sum%MOD);
}

int main(void) {
    int N;
    scanf("%d", &N);
    proc(N);
    return 0;
}
