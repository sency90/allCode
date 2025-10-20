#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if(v.empty()) v.push_back(x);
            else {
                if(v.back() < x) v.push_back(x);
                else {
                    auto it = lower_bound(v.begin(), v.end(), x);
                    *it = x;
                }
            }
        }
        printf("%lu\n", v.size());
        v.clear();
    }
    return 0;

}