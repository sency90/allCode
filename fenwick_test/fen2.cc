#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;
vector<int> v;
using ll = long long;
constexpr int N = 8;
int fen[N+1];
void update(int at, int by) {
    for(;at;at-=at&-at) fen[at] += by;
}
void range_update(int l, int r, int by) {
    if(l>r) swap(l,r);
    assert(l>=1);
    if(l!=0) update(l-1,-by);
    update(r,by);
}
ll query(int at) {
    if(at==0) return 0LL;
    assert(at>0);
    ll ret=0;
    for(;at<=N;at+=at&-at) ret += fen[at];
    return ret;
}
int main() {
    range_update(1,5,3); puts("[0,5] += 3");
    range_update(3,7,2); puts("[3,7] += 2");
    range_update(4,6,9); puts("[4,6] += 9");
    for(int i=0; i<=N; i++) {
        printf("query(%d): %lld\n", i, query(i));
    }
    return 0;
}
