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
    for(;at<=N;at+=at&-at) {
        fen[at] += by;
    }
}
ll query(int at) {
    if(at<=0) return 0LL;
    ll ret = 0;
    for(;at;at-=at&-at) {
        ret += fen[at];
    }
    return ret;
}
ll range_qeury(int l, int r) {
    if(l>r) swap(l,r);
    assert(r<=N);
    return query(r)-query(l-1);
}
int main() {
    update(3,3);
    update(7,2);
    update(4,7);
    printf("range_query(3,5): %lld\n", range_qeury(3,5));
    printf("range_query(6,7): %lld\n", range_qeury(6,7));
    return 0;
}
