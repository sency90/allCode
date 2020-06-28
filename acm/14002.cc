#include <cstdio>
using namespace std;
int v[1001], dp[1001], p[1001];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        dp[i]=1;
    }
    int mx=1, mxi=n;
    for(int i=n-1; i>=1; i--) {
        for(int j=n; j>i; j--) {
            if(v[i]<v[j]) {
                if(dp[i]<=dp[j]) {
                    dp[i]=dp[j]+1;
                    p[i] = j;
                    if(mx < dp[i]) {
                        mx = dp[i];
                        mxi = i;
                    }
                }
            }
        }
    }
    printf("%d\n", mx);
    for(int i=mxi; i!=0; i=p[i]) {
        printf("%d ", v[i]);
    }

    return 0;
}
