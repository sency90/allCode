#include <set>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <map>
using namespace std;
typedef bitset<11> b11;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;

set<ul> validNextBit[12][1<<11];
map<ul, ll> d[12][12];
int w,h,bitlim;
void setBit(int pos, b11 before, b11 after) {
    if(pos == h) {
        validNextBit[h][before.to_ulong()].insert(after.to_ulong());
        return;
    }

    if(!before.test(pos)) setBit(pos+1,before,after.set(pos));
    else setBit(pos+1,before,after);

    if(pos<h-1 && before.test(pos)==before.test(pos+1)) {
        setBit(pos+2,before,after.set(pos).set(pos+1));
    }
}

ll solve(int w, b11 curState) {
    ul s = curState.to_ulong();
    if(w==-1) {
        if(s == bitlim-1) return 1LL;
        else return 0LL;
    }
    if(d[w][h].count(s)) return d[w][h][s];
    ll &ret = d[w][h][s] = 0LL;

    for(auto &ns : validNextBit[h][s]) ret += solve(w-1, ns);
    return ret;
}

int main() {
    for(h=1; h<=11; h++) {
        int lim = 1<<h;
        for(int before=0; before<lim; before++) {
            setBit(0,before,0);
        }
    }
    while(true) {
        scanf("%d%d",&w,&h);
        if(w==0&&h==0) return 0;
        if(h<w) swap(w,h);
        bitlim = 1<<h;
        printf("%lld\n", solve(w,0));
    }
    return 0;
}
