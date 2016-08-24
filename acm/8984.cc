#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define UP 0
#define DOWN 1
vector<pair<long long, long long> > s;
map<long long, long long> d[2];
int ABS(int x) { return x<0?-x:x; }
long long dist(const pair<int,int> &p) {
    return ABS(p.first-p.second);
}
int main() {
    int n;
    long long x,y,z,l;
    scanf("%d%lld",&n,&l);
    s.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld",&x,&y);
        s[i]=make_pair(x,y);
    }
    sort(s.begin(), s.end());
    long long ans = 0LL, t1, t2;
    for(int i=0; i<n; i++) {
        x=s[i].first; y=s[i].second; z=dist(s[i])+l;
        t1 = max(d[UP][x], d[DOWN][y]+z);
        t2 = max(d[DOWN][y], d[UP][x]+z);
        d[UP][x] = t1; d[DOWN][y] = t2;
        ans = max(ans, max(t1,t2));
    }
    printf("%lld", ans);
    return 0;
}
