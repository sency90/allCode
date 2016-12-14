#include <cstdio>
#include <algorithm>
#include <vector>
#define sf second.first
#define ssf second.second.first
#define sss second.second.second
using namespace std;
typedef long long ll;
typedef vector<pair<ll, pair<ll, pair<ll, int>>>> vpllli;
vector<pair<ll, pair<ll, pair<ll, int>>>> v;
vector<int> ans[100001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        ll x[3];
        for(int j=0; j<3; j++) scanf("%lld",&x[j]);
        sort(x,x+3);
        v.push_back(make_pair(x[0],make_pair(x[1],make_pair(x[2],i+1))));
    }
    sort(v.begin(), v.end());
    int rem=-1;
    while(true) {
        bool good = true;
        for(auto it=v.begin(); it-v.begin()<n; it++) {
            if(it->sf==(it+1)->sf && it->ssf==(it+1)->ssf) {
                good=false;
                (it+1)->first += it->first;
                if((it+1)->first > (it+1)->sf) {
                    swap((it+1)->first, (it+1)->sf);
                    if((it+1)->sf > (it+1)->ssf) {
                        swap((it+1)->sf,(it+1)->ssf);
                    }
                }
                *it=*(it+1);
                rem=it-v.begin();
                auto jt = lower_bound(it+2,v.end(),*(it+1));
                if(jt==v.end()) break;
                ans[(jt+1)->sss].push_back((jt+1)->sss);
                it = jt;
            }
        }
        v.erase(unique(v.begin(), v.end()),v.end());
        n=v.size();
        if(good) break;
    }
    if(rem==-1) {
        puts("1");
        printf("%d\n",v.back().sss);
    } else {
        printf("%lu\n", ans[rem].size());
        for(auto &p: ans[rem]) {
            printf("%d ", p);
        }
    }
    return 0;
}
