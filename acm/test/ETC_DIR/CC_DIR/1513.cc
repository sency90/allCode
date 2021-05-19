#include <cstdio>
using namespace std;
const int MOD = 1000007;
int pos[51][51], dp[51][51][51][51];
int main() {
    int n,m,c,x,y;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1; i<=c; i++) {
        scanf("%d%d",&x,&y);
        pos[x][y]=i;
    }

    dp[1][0][0][0] = 1;
    /*
    if(pos[1][1]>0) dp[1][1][1][1] = 1;
    else dp[1][1][0][0] = 1;
    */

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(pos[i][j]>0) { //(i,j)가 오락실인 경우
                for(int cnt=1; cnt<=c; cnt++) {
                    for(int k=cnt-1; k<pos[i][j]; k++) {
                        dp[i][j][cnt][pos[i][j]] += dp[i-1][j][cnt-1][k] + dp[i][j-1][cnt-1][k];
                        dp[i][j][cnt][pos[i][j]] %= MOD;
                    }
                }
            } else { //(i,j)가 오락실이 아닌 경우
                for(int cnt=0; cnt<=c; cnt++) {
                    for(int k=cnt; k<=c; k++) {
                        dp[i][j][cnt][k] += dp[i-1][j][cnt][k] + dp[i][j-1][cnt][k];
                        dp[i][j][cnt][k] %= MOD;
                    }
                }
            }
        }
    }
    for(int cnt=0; cnt<=c; cnt++) {
        int ans = 0;
        for(int k=cnt; k<=c; k++) {
            ans += dp[n][m][cnt][k];
            ans %= MOD;
        }
        printf("%d ", ans);
    }
    return 0;
}

