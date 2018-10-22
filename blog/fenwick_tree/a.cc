#include <cstdio>
#include <cassert>
using namespace std;
constexpr int N=100000;
int fen[N+1];
void update(int at, int by) {
    assert(1<=at && at<=N);
    for(;at<=N;at+=at&-at) fen[at]+=by;
}
int query(int at) {
    if(at==0) return 0;

    assert(1<=at && at<=N);
    int ret=0;
    for(;at;at-=at&-at) ret+=fen[at];
    return ret;
}
int main() {
    int Q; scanf("%d", &Q);
    while(Q--) {
        int type; scanf("%d", &type);
        if(type==1) { //update
            int at,by;
            scanf("%d%d",&at,&by);
            update(at,by);
        } else if(type==2) { //query
            int L,R;
            scanf("%d%d",&L,&R);
            printf("%d\n", query(R)-query(L-1));
        } else exit(1); //unreachable code
    }
    return 0;
}
