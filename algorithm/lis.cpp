#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
using pii = pair<int,int>;
int v[100001];
pii dp[100001];
stack<int> s;
pii f(int x) {
    if(x==1) return pii(1,1);
    if(dp[x].first != 0) return dp[x];
    dp[x].first=1;
    for(int i=1; i<x; i++) {
        if(v[i]<v[x]) {
            if(dp[x].first < f(i).first+1) {
                dp[x] = pii(f(i).first+1, i);
            }
        }
    }
    return dp[x];
}
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    int mxlen=-1, mxi=0;
    for(int i=1; i<=n; i++) {
        if(mxlen < f(i).first) {
            mxlen = f(i).first;
            mxi = i;
        }
    }
    for(int i=mxi; ; i=dp[i].second) {
        s.push(v[i]);
        if(dp[i].first==1) break;
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    puts("");
    return 0;
}
