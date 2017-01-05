#include <iostream>
#define MAX 101 

using namespace std;

long long dp[MAX][MAX][MAX];
long long mod = 1000000007;

int main() {
    int N, L, R;
    scanf("%d", &N);    
    scanf("%d", &L);    
    scanf("%d", &R);

    dp[1][1][1]= 1;

    for(int i=1; i<=N-1; i++){
        for(int m=1; m<=L; m++){
            for(int k=1; k<=R; k++){
                if(m+1<=L) {
                    dp[i+1][m+1][k]+= dp[i][m][k];
                    dp[i+1][m+1][k]%=mod;
                }
                if(k+1<=R){
                    dp[i+1][m][k+1]+=dp[i][m][k];
                    dp[i+1][m][k+1]%= mod;
                }
                dp[i+1][m][k]+= dp[i][m][k]* (i-1);
                dp[i+1][m][k]%= mod;
            }
        }
    }
    printf("%lld\n",dp[N][L][R]);
    return 0;
}