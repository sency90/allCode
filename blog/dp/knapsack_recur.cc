#include <cstdio>
#include <vector>
#include <algorithm>
#define w first
#define v second
using namespace std;
typedef pair<int,int> pii;
vector<pii> I;
int N,W,dp[101][10001];
int f(int i, int m) {
    if(i>=N) return 0;

    int &ans=dp[i][m];
    if(ans>=0) return ans; //dp배열에 메모된적이 있다면 계산 하지 않고 바로 리턴
    else ans=0; //dp배열에 메모된적이 없다면 -1인 dp배열값을 0으로 바꿔준다. (방문한적이 있음을 표시)

    if(m-I[i].w>=0) ans = max(f(i+1,m-I[i].w)+I[i].v, f(i+1,m));
    else ans = f(i+1, m);
    return ans;
}
int main() {
    memset(dp,-1,sizeof(dp)); //dp 테이블을 -1로 초기화
    scanf("%d%d", &N,&W);
    for(int i=0; i<N; i++) {
        int wei,val;
        scanf("%d%d", &wei,&val);
        I.emplace_back(pii(wei,val));
    }
    printf("%d\n", f(0,W));
    return 0;
}
