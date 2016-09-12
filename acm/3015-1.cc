#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<pair<ll,ll> > s;
int main() {
    ios::sync_with_stdio(false);
    pair<ll, ll> tmp;
    ll d, ans=0LL;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> d;
        tmp = {d,1LL};
        while(!s.empty()) {
            if(s.top().first<d) {
                ans+=s.top().second;
                s.pop();
            } else if(s.top().first==d) {
                ans+=s.top().second;
                tmp.second+=s.top().second;
                s.pop();
            } else break;
        }
        if(!s.empty()) ans++;
        s.push(tmp);
    }
    printf("%lld", ans);
    return 0;
}
