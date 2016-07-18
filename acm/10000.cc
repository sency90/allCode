#include <set>
#include <cstdio>
#include <queue>
using namespace std;
set<long long> chk;
struct LR{
    long long l, r;
    LR() {}
    LR(long long ll, long long rr) : l(ll), r(rr) {}
    bool operator<(const LR &rhs) const {
        if(l==rhs.l) return r < rhs.r;
        else return l > rhs.l;
    }
};
priority_queue<LR> h;
int main() {
    long long n,x,r;
    scanf("%lld",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&r);
        h.push(LR(x-r,x+r));
    }
    long long cnt = 1LL;
    while(!h.empty()) {
        LR t = h.top(); h.pop();
        if(chk.count(t.l)>0) {
            if(chk.count(t.r)>0) cnt+=2;
            else {
                chk.insert(t.r);
                cnt++;
            }
        } else {
            chk.insert(t.l);
            chk.insert(t.r);
            cnt++;
        }
    }
    printf("%lld", cnt);
    return 0;
}

