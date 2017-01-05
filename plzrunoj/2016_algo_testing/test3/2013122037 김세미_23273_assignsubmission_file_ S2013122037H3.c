
#include <stdio.h>
#include <string.h>

int main()
{
    int n, l, r;                //입력값 변수
    long long B[101][101][101]; //B[N][L][R] N개의 빌딩이 있을 때 왼쪽에서 L개 오른쪽에서 R개 보이는 경우의 수
    
    memset(B, 0, sizeof(B));    //배열 초기화
    
    //초기값이 따로 필요한 경우 초기화
    B[1][1][1] = 1;
    B[2][2][1] = 1;
    B[2][1][2] = 1;
    
    scanf("%d %d %d", &n, &l, &r);
    
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= l; j++)
            for (int k = 1; k <= r; k++)
            {
                /*
                 B[n][l][r] 은
                 B[n-1][l-1][r]의 경우에서 제일 왼쪽에 하나의 빌딩을 더 넣은 경우(1가지)와
                 B[n-1][l][r-1]의 경우에서 제일 오른쪽에 하나의 빌딩을 더 넣은 경우(1가지)
                 B[n-1][l][r]의 경우에서 양끝을 제외한 사이에 넣는 경우(n-2가지)
                 세가지의 합으로 구할 수 있다.
                 */
                B[i][j][k] = B[i - 1][j - 1][k] + B[i - 1][j][k - 1] + B[i - 1][j][k] * (i - 2);
                B[i][j][k] %= 1000000007;
            }
    printf("%lld\n", B[n][l][r]);
    return 0;
}
