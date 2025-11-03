#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
vector<vector<int>> storage;
unordered_map<int, vector<int>> tree, ntree;
unordered_map<int, ll> cnt;
unordered_map<int, bool> chk;
vector<int> ans;
ll LIM = (1LL<<33);
ll CntDfs(int x) {
    if(tree[x].empty()) {
        int m = v.size()-1;
        auto it = lower_bound(storage[m].rbegin(), storage[m].rend(), x);
        if(it != storage[m].rend() && x==*it) {
            return cnt[x] = 1;
        }
        else return cnt[x] = 0;
    }
    if(chk[x]) return cnt[x];
    chk[x]=true;
    for(int i = tree[x].size() - 1; i >= 0; i--) {
        int y = tree[x][i];
        ll res = CntDfs(y);
        if(res) {
            cnt[x] += res;
            ntree[x].push_back(y);
        }
        if(cnt[x]>=LIM) cnt[x]=LIM;
    }
    return cnt[x];
}
bool FindDfs(int x, ll k) {
    if(ntree[x].empty() && k == 1) {
        return true;
    }
    for(int i=0; i<ntree[x].size(); i++) {
        int y = ntree[x][i];
        if(cnt[y] < k)
            k -= cnt[y];
        else {
            if(FindDfs(y, k)) {
                ans.push_back(y);
                return true;
            }
        }
    }
    return false;
}
void Init(int n) {
    v.clear();
    storage.clear();
    storage.resize(n, vector<int>());
    tree.clear();
    ntree.clear();
}
void GetTree(int m, int x) {
    for(int i = storage[m].size() - 1; i >= 0; i--) {
        int y = storage[m][i];
        if(y >= x) break;
        tree[y].push_back(x);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; 
        ll k; 
        cin >> n >> k;
        Init(n);
        // storage[d] = tree의 깊이 [d]에 해당하는 정점들이 list형태로 저장되어있는데, 이 list는
        // 별도로 정렬하지 않아도 항상 내림차순으로 값이 들어가 정렬된 상태를 유지한다.
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(v.empty()) {
                tree[0].push_back(x);
                v.push_back(x);
                storage[v.size() - 1].push_back(x);
            } else {
                auto it = lower_bound(v.begin(), v.end(), x);

                if(it == v.end()) {
                    int m = v.size() - 1;
                    GetTree(m, x);
                    v.push_back(x);
                    storage[v.size() - 1].push_back(x);
                } else {
                    if(it == v.begin()) {
                        tree[0].push_back(x);
                    } else {
                        int m = it - v.begin() - 1;
                        GetTree(m, x);
                    }
                    *it = x;
                    storage[it - v.begin()].push_back(x);
                }
            }
        }

        ans.clear();
        cnt.clear();
        chk.clear();
        CntDfs(0);
        FindDfs(0, k);
        printf("%lu\n", ans.size());
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        puts("");
    }
    return 0;
}