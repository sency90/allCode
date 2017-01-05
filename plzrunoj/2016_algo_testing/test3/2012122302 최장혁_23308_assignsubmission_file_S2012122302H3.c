#include <cstdio>
#define MOD 1000000007
int cache[101][101][101] = {0};
int main() {
    cache[1][1][1] = cache[2][1][2] = cache[2][2][1] = 1;
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);
    for(int i = 3; i<=N; i++)
        for(int j=1; j<=L; j++)
            for(int k=1; k<=R; k++)
                cache[i][j][k] = (cache[i-1][j-1][k]%MOD + cache[i-1][j][k-1]%MOD + cache[i-1][j][k]*(i-2)%MOD) % MOD;
    printf("%d\n", cache[N][L][R]);
    return 0;
}
