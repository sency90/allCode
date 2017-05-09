#include <cstdio>
#include <vector>
#include <algorithm>
#define w first
#define v second
using namespace std;
typedef pair<int,int> pii;
vector<pii> I;
int N,W;
int f(int i, int m) {
    if(i>=N) return 0;

    int ans=0;
    if(m-I[i].w>=0) ans = max(f(i+1,m-I[i].w)+I[i].v, f(i+1,m));
    else ans = f(i+1, m);
    return ans;
}
int main() {
    scanf("%d%d", &N,&W);
    for(int i=0; i<N; i++) {
        int wei,val;
        scanf("%d%d", &wei,&val);
        I.emplace_back(pii(wei,val));
    }
    printf("%d\n", f(0,W));
    return 0;
}
