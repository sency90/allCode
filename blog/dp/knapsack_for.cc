#include <cstdio>
#include <vector>
#include <algorithm>
#define w first
#define v second
using namespace std;
typedef pair<int,int> pii;
vector<pii> I;
int N,W,dp[10001];
int main() {
    scanf("%d%d", &N,&W);
    for(int i=0; i<N; i++) {
        int wei,val;
        scanf("%d%d", &wei,&val);
        I.emplace_back(pii(wei,val));
    }
    for(int i=0; i<N; i++) {
        for(int j=W; j>=I[i].w; j--) {
            dp[j]=max(dp[j], dp[j-I[i].w]+I[i].v);
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}
