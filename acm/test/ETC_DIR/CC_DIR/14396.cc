#include <cstdio>
using namespace std;
const int mod = 1e9+9;
int com[2001][2001];
int combi(int n, int r) {
    if(n==0) return 0;
    if(n==r||r==0) return 1;
    if(com[n][r]) return com[n][r];
    return com[n][r]=combi(n-1,r)+combi(n-1,r-1);
}
int dp[2001], d[2001][2001];
int fact(int n) {
    if(n==0) return 1;
    if(dp[n]) return dp[n];
    dp[n]=n*fact(n-1);
    dp[n]%=mod;
    return dp[n];
}
int f(int n, int m) {
    if(n==2&&m==1) return 1;
    else if(n<=2&&m<=1) return 0;
    int &ret = d[n][m];
    if(ret) return ret;

    for(int i=0; i<=m; i++) {
        ret=ret+(((long long)f(n-1,m-i)*combi(n-1,i))%mod*fact(i))%mod;
        ret%=mod;
    }
    return ret;
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    printf("%d\n", f(n,m));
    return 0;
}
