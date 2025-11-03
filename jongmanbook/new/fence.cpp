#include <bits/stdc++.h>
using namespace std;
struct Info {
    int h, idx;
    Info() {}
    Info(int h, int idx):h(h),idx(idx) {}
    bool operator<(const Info & rhs) const {
        if(h == rhs.h) return idx < rhs.idx;
        else return h<rhs.h;
    }
};
vector<Info> storage;
void Init() {
    storage.clear();
    storage.emplace_back(-1,0);
}
int h[20002];
int ans[20002];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        Init();

        int N; cin >> N;
        for(int i=1; i<=N; i++) {
            cin >> h[i];
        }
        for(int i=1; i<=N; i++) {
            while(h[i] <= storage.back().h) {
                storage.pop_back();
            }
            ans[i] = (i-storage.back().idx)*h[i];
            storage.emplace_back(h[i], i);
        }

        storage.clear();
        storage.emplace_back(-1,N+1);
        for(int i=N; i>=1; i--) {
            while(h[i] <= storage.back().h) {
                storage.pop_back();
            }
            ans[i] += (storage.back().idx-i-1)*h[i];
            storage.emplace_back(h[i],i);
        }
        int mx_ans = 0;
        for(int i=1; i<=N; i++) {
            mx_ans = max(mx_ans, ans[i]);
        }
        printf("%d\n", mx_ans);
    }
    return 0;
}