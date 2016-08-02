#include <cstdio>
#include <vector>
using namespace std;
struct LR{
    long long l, r;
    LR(){} LR(long long l, long long r) : l(l), r(r) {}
    bool operator<(const LR &rhs) const {
        if(l==rhs.l) return r < rhs.r;
        else return l > rhs.l;
    }
};
vector<LR> v;
int main() {
    long long n,x,r;
    scanf("%lld",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&r);
        v.push_back(LR(x-r, x+r));
    }
    long long cnt = 1LL;
    int top = 0;
    for(int i=0; i<n; i++) {
        if(v[i].l < v[s[top][0]].r) {
            if(s[top][1]==v[i].l) s[top][1]=v[i].r;
        }
        s[top][0] = i;
        s[top][1] = v[i].l;
        top++;
    }
    printf("%lld", cnt);
    return 0;
}

