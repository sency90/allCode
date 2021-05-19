#include <stdio.h>
#include <vector>
using namespace std;
const long long MOD = 1000000000LL;
vector<pair<int, int> > v;
long long d[500];
long long factorial(long long x) {
    if(x==1LL) return 1LL;
    if(d[x]>0) return d[x];
    return d[x] = (x*factorial(x-1LL))%MOD;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(j%i == 0 && i!=1) continue;
            v.push_back(make_pair(i,j));
        }
    }
    for(auto &p : v) {
        printf("%d %d\n", p.first, p.second);
    }
    long long cnt, ans=0LL;
    for(int i=0; i<v.size(); i++) {
        cnt = 1LL;
        for(int j=i+1; j<v.size(); j++) {
            if(!(v[i].second<=v[j].first && v[j].second<=v[i].first)) cnt++;
        }
        printf("cnt: %lld\n", cnt);
        ans = (ans + factorial(cnt))%MOD;
    }
    printf("%lld", ans);
    return 0;
}
