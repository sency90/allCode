#include <stdio.h>
#include <algorithm>
bool dp[80][80][80][80];
int v[16];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    dp[0][0][0][0] = true;
    for(int i=0; i<n; i++) {
        for(int a=79; a>=0; a--) {
            for(int b=79; b>=0; b--) {
                for(int c=79; c>=0; c--) {
                    for(int d=79; d>=0; d--) {
                        if(!dp[a][b][c][d]) continue;
                        if(v[i]+a<80) dp[a+v[i]][b][c][d] = true;
                        if(v[i]+b<80) dp[a][b+v[i]][c][d] = true;
                        if(v[i]+c<80) dp[a][b][c+v[i]][d] = true;
                        if(v[i]+d<80) dp[a][b][c][d+v[i]] = true;
                    }
                }
            }
        }
    }

    int ans=-1;
    for(int i=1; i<80; i++) {
        for(int j=1; j<80; j++) {
            if(dp[i][i][j][j]) {
                ans = std::max(ans, i*j);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
