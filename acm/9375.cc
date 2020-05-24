#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
typedef long long ll;
map<string, ll> dic;
string s, type;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> s >> type;
            dic[type]++;
        }
        ll ans = 1LL;
        for(auto &it : dic) {
            ans *= (it.second+1LL);
        }
        printf("%lld\n", ans-1LL);
        dic.clear();
    }
    return 0;
}
