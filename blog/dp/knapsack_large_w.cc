#include <cstdio>
#include <vector>
#include <algorithm>
#define w first
#define v second
using namespace std;
typedef pair<int,int> pii;
vector<pii> I;
int N,W;
pii dp[101];
pii f(int idx) {
    if(idx==0) return pii(0,0); //base case

    //dp배열에 메모되어 있으면 바로 리턴~!!
    pii& ret = dp[idx];
    if(ret.w>=0) return ret;
    else ret.w=0;

    //메모되어 있지 않으면 계산!
    for(int i=0; i<idx; i++) {
        pii prv = f(i);
        int cw=prv.w+I[idx].w, cv=prv.v+I[idx].v;
        if(cw<=W) {
            if(cv > ret.v) ret = pii(cw, cv);
            else if(cv == ret.v) {
                if(cw < ret.w) ret = pii(cw, cv);
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d%d",&N,&W);
    I.emplace_back(pii(0,0)); //I배열의 index 맞춰주기 위해 넣었음. 아무의미 없음.
    for(int i=0; i<=N; i++) dp[i]=pii(-1,0);
    for(int i=0; i<N; i++) {
        int wei,val;
        scanf("%d%d", &wei,&val);
        I.emplace_back(pii(wei,val));
    }
    printf("%d\n",f(N).v);
    return 0;
}
