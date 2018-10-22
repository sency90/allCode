#include <cstdio>
#include <cassert>
using namespace std;
using ll = long long;
constexpr int N=100000;
ll tadd[N+1], tmul[N+1];
void inupdate(int at, ll mul, ll add) {
    assert(1<=at && at<=N);
    for(;at<=N;at+=at&-at) {
        tmul[at] += mul;
        tadd[at] += add;
    }
}
void range_update(int l, int r, ll by) {
    inupdate(l, by, -by*(l-1));
    inupdate(r+1, -by, by*r);
}
ll range_query(const int at) {
    if(at==0) return 0;
    assert(1<=at && at<=N);

    ll mul=0, add=0;
    for(int i=at;i;i-=i&-i) {
        mul += tmul[i];
        add += tadd[i];
    }
    return at*mul+add;
}
int main() {
    int Q; scanf("%d", &Q);
    while(Q--) {
        int type; scanf("%d", &type);
        if(type==1) { //range_update
            int L,R,by;
            scanf("%d%d%d",&L,&R,&by);
            range_update(L,R,by);
        } else if(type==2) { //range_query
            int L,R;
            scanf("%d%d",&L,&R);
            printf("%lld\n", range_query(R)-range_query(L-1));
        } else exit(1); //unreachable code
    }
    return 0;
}
