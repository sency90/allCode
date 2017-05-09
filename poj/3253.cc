#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<int, vector<int>, greater<int>> mnh;
bool cmp(const int &lhs, const int &rhs) { return lhs>rhs; }
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int d; scanf("%d", &d);
        mnh.push(d);
    }
    ll ans=0LL;
    while(mnh.size()>1) {
        int x=mnh.top(); mnh.pop();
        int y=mnh.top(); mnh.pop();
        ans+=x+y;
        mnh.push(x+y);
    }
    printf("%lld\n", ans);
    return 0;
}
