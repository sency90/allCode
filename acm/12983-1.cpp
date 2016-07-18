#include <stdio.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
vector<long long> v(10000001);
priority_queue<long long, vector<long long>, greater<long long> > h;
int main() {
    long long x, cnt=0LL, px=0LL;
    h.push(1);
    while(!h.empty()) {
        x = h.top(); h.pop();
        if(px==x) continue;
        v[cnt++]=x;
        if(cnt == 10000000) break;
        px = x;
        h.push(2*x+1);
        h.push(3*x+1);
    }

    int t, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &d);
        printf("%lld\n", v[d-1]);
    }
    return 0;
}
