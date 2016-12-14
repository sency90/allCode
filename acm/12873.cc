#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
queue<int> q;
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    ll mv;
    for(ll i=n,j=1LL; i>=1; i--, j++) {
        ll t = j*j*j;
        if(t<i) mv=t-1LL;
        else mv=(t-1LL)%i;
        for(int j=0; j<mv; j++) {
            q.push(q.front());
            q.pop();
        }
        if(q.size()!=1) q.pop();
    }
    printf("%d\n", q.front());
    return 0;
}
