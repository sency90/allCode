#include <stdio.h>
#include <vector>
using namespace std;
vector<long long> v;
long long ans=0, n;
bool vnv(long long x) {
    long long sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum+=v[i]/x;
    }
    printf("sum: %lld\n", sum);
    if(sum>=n) return true;
    else return false;
}
void binsearch(long long l, long long r) {
    if(l<=r) return;
    long long m = (l+r)/2;
    if(vnv(m)) {
        printf("%lld\n", m);
        if(ans < m) ans=m;
        binsearch(m+1,r);
    } else binsearch(l,m-1);
}
int main() {
    long long k, mx=0, d;
    scanf("%lld%lld",&k,&n);
    for(int i=0; i<k; i++) {
        scanf("%lld", &d);
        v.push_back(d);
        if(mx < d) mx = d;
    }
    binsearch(1,mx);
    printf("%lld", ans);
    return 0;
}
