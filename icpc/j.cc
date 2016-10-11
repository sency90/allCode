#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<long long, long long> pll;
vector<long long> s;
vector<pair<long long, long long> > e;
const long long ninf = -1e10;
const long long basis = 1e10;
int main() {
    int n;
    long long x, y, l, mx=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&y);
        if(x>y)swap(x,y);
        x+=basis; y+=basis;
        s.push_back(x);
        e.push_back(make_pair(y,y-x));
    }
    scanf("%lld", &l);
    sort(s.begin(), s.end());
    for(auto &p : s) {
        printf("%lld ",p);
    }
    puts("\n");
    for(auto &p : e) {
        printf("%lld %lld\n",p.first, p.second);
    }
    puts("");
    sort(e.begin(), e.end());
    for(int i=0; i<s.size(); i++) {
        long long endlim = s[i]+l;
        printf("endlim: %lld\n", endlim);
        auto it = upper_bound(e.begin(), e.end(), pll(endlim,0));
        auto it2 = lower_bound(e.begin(), e.end(), pll(s[i],0));
        long long tmp = it-it2-1;
        printf("%lld\n",tmp);
        mx = max(mx,tmp);
    }
    printf("%lld", mx);
    return 0;
}
