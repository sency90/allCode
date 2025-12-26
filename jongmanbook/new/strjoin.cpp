#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> mnh;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            mnh.push(x);
        }
        int ans=0;
        while(mnh.size()>=2) {
            int x = mnh.top(); mnh.pop();
            int y = mnh.top(); mnh.pop();
            mnh.push(x+y);
            ans += (x+y);
        }
        printf("%d\n", ans);
        while(!mnh.empty()) mnh.pop();
    }
    return 0;
}