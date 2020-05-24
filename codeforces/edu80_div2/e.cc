#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
int n,m;
vector<int> fen,a;
pii ans[300001];
int lastPos[300001];
void update(int at, int by) {
    for(; at<=n+m; at+=at&-at) fen[at] += by;
}
int query(int at) {
    int ret = 0;
    for(; at>0; at-=at&-at) ret += fen[at];
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    fen.clear(); fen.resize(n+m+1, 0);
    for(int i=1; i<=n; i++) {
        update(m+i,1);
        lastPos[i] = m+i;
        ans[i].first = i;
    }
    for(int i=1; i<=m; i++) {
        int x; cin >> x;
        a.push_back(x);

        ans[x].first = 1;
        ans[x].second = max(ans[x].second, query(lastPos[x]));
        update(lastPos[x],-1);
        update(m-i+1, 1);
        lastPos[x] = m-i+1;
    }
    for(int i=1; i<=n; i++) {
        ans[i].second = max(ans[i].second, query(lastPos[i]));
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
