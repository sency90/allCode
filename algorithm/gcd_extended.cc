#include <cstdio>
#include <algorithm>
using namespace std;
pair<long long, long long> ex_gcd(long long x, long long y) {
    if(y==0) return make_pair(1,0);
    pair<long long, long long> tmp = ex_gcd(y,x%y);
    return make_pair(tmp.second, tmp.first - tmp.second*(x/y));
}
int main() {
    long long x, y;
    scanf("%lld%lld",&x,&y);
    pair<long long, long long> ans = ex_gcd(x,y);
    printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}
