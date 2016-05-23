#include<cstdio>
#define MOD 1000000000
int N;
int dp[105][10][4];
int f(int n,int d,int bit) {
    if(dp[n][d][bit]) return dp[n][d][bit];
    if(n == N) {
        if(bit == 3) return 1;
        else return 0;
    }
    int ret = 0;
    if(d < 9) ret += f(n+1 , d+1 , bit|(d+1 == 9 ? 2 : 0) ); ret %= MOD;
    if(d > 0) ret += f(n+1 , d-1 , bit|(d-1 == 0 ? 1 : 0) ); ret %= MOD;
    return dp[n][d][bit] = ret;
}
int main() {
    scanf("%d",&N);
    int ans = 0;
    for(int i=1;i<10;i++) {
        ans += f(1,i,i == 9 ? 2 : 0); ans %= MOD;
    }
    printf("%d",ans);
}
