#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<int> w;
struct Info {
    int x,idx;
    Info(){}
    Info(int x, int idx):x(x),idx(idx) {}
    bool operator<(const Info & rhs) const {
        return x<rhs.x;
    }
};
vector<Info> v;
int p[501];
void dfs(int idx) {
    if(idx<0) return;
    dfs(p[idx]);
    printf("%d ", w[idx]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,x; cin >> n;
        w.clear(); v.clear();
        memset(p,-1,sizeof(p));
        for(int i=0; i<n; i++) {
            cin >> x;
            w.push_back(x);
            if(v.empty()) {
                v.emplace_back(x,i);
            }
            else {
                auto it = lower_bound(v.begin(), v.end(), Info(x,i));
                if(it == v.end()) {
                    p[i] = v.back().idx;
                    v.emplace_back(x, i);
                }
                else {
                    *it = Info(x,i);
                    if(it != v.begin()) {
                        p[i] = (it-1)->idx;
                    }
                }
            }
        }

        dfs(v.back().idx);
        puts("");
    }
    return 0;
}