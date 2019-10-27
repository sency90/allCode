#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int N = 1e5;
ll tmul[N+1], tadd[N+1];
ll range_query(int l, int r) {
    ll M=0LL, A=0LL, ret=0LL;
    for(int i=l-1; i>0; i-=i&-i) {
        M += tmul[i];
        A += tadd[i];
    }
    ret -= M*(l-1)+A;
    M=0LL; A=0LL;
    for(int i=r; i>0; i-=i&-i) {
        M += tmul[i];
        A += tadd[i];
    }
    ret += M*r+A;
    return ret;
}
void range_update(int l, int r, ll by) {
    for(int i=l; i<=N; i+=i&-i) {
        tmul[i] += by;
        tadd[i] += -by*(l-1);
    }
    for(int i=r+1; i<=N; i+=i&-i) {
        tmul[i] += -by;
        tadd[i] += by*r;
    }
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t,l,r,by;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1) { //update
            scanf("%d",&by);
            printf("range_update[%d,%d] <- %d\n",l,r,by);
            range_update(l,r,by);
            for(int i=1; i<=8; i++) printf("(%lld,%lld) ", tmul[i],tadd[i]);
            puts("");
        }
        else { //query
            printf("range_query[%d,%d] -> %lld\n", l,r,range_query(l,r));
        }
    }
    return 0;
}
