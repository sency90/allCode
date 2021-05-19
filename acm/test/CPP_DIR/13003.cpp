#include <stdio.h>
const long long MOD = 1000000007LL;
//d[pos][last]로 풀었다. 마지막에 본 수가 last이면 그 다음에 나오는 경우의 수는 앞에 부분이 어떻게 되었는지와 관계없이 경우의 수가 일정하다.
//내가 이 문제를 1번 더 풀었는데 그건 13003-1.cpp이다.
//dotorya님 소스코드를 보고 깨달은게...  %연산과 *연산을 덧셈과 뺄셈으로 바꾸면서 엄청난 시간단축을 경험할 수 있었다.
//기억이 안나면 두 소스코드를 보고 비교해 볼 것.
long long d[2020][2020];
int main() {
    int n, l;
    scanf("%d%d", &n,&l);
    for(int i=1; i<=n; i++) {
        d[1][i]=1LL;
    }
    for(int i=1; i<l; i++) {
        for(int last=1; last<=n; last++) {
            for(int j=1; j<=n; j++) {
                if(last*j<=n) d[i+1][last*j]=(d[i+1][last*j] + d[i][last])%MOD;
                else break;
            }
        }
    }

    long long sum = 0LL;
    for(int i=1; i<=n; i++) {
        sum = (sum+d[l][i])%MOD;
    }
    printf("%lld", sum);
    return 0;
}
