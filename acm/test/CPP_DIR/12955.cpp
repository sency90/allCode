#include <stdio.h>
int N, M, K;
long long ans = 0LL, res[12];
int str[12];
bool isPalin(int s, int e) {
    while(s<e) if(str[s++]!=str[e--]) return false;
    return true;
}
void dfs(int n, int c) {
    int cnt=0;
    if(n==N) {
        for(int i=0; i<=n-M; i++) {
            if(isPalin(i,i+M-1)) cnt++;
        }
        if(cnt>=K) ans+=res[c];
        return;
    }
    for(int i=0; i<=c; i++) {
        str[n]=i;
        if(i==c) dfs(n+1, c+1);
        else dfs(n+1, c);
        str[n]=-1;
    }
}
int main() {
    int j=1;
    res[0]=1LL;
    for(int i=26; i>=16; i--) {
        res[j] = res[j-1]*i;
        j++;
    }
    res[0]=0LL;
    scanf("%d%d%d", &N,&M,&K);
    dfs(0,0);
    printf("%lld", ans);
    return 0;
}
