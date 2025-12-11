#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<pii> russia, korea;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int x;
        russia.clear();
        korea.clear();
        for(int i=0; i<n; i++) {
            cin >> x;
            russia.emplace_back(x,i);
        }
        for(int i=0; i<n; i++) {
            cin >> x;
            korea.emplace_back(x,n);
        }

        sort(russia.begin(), russia.end());
        sort(korea.begin(), korea.end());

        int cnt=0,k=0;
        for(int i=0; i<russia.size(); i++) {
            auto it = lower_bound(korea.begin()+k, korea.end(), russia[i]);
            if(it == korea.end()) continue;
            k = (it-korea.begin())+1;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}