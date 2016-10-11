#include <cstdio>
#include <algorithm>
using namespace std;
pair<long long, long long> ex_gcd(long long a, long long b) {
    if(b==0) return make_pair(1,0);
    auto tmp = ex_gcd(b,a%b);
    return make_pair(tmp.second, tmp.first-(a/b)*tmp.second);
}
int main() {
    long long x, y;
    scanf("%lld%lld",&x,&y);
    auto ans = ex_gcd(x,y);
    printf("%lld, %lld\n",ans.first,ans.second);
    return 0;
}
