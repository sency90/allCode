#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const long long MOD = 20091101LL;
map<int, vector<int> > last;
int p[100001], d[100001];
int f(int x) {
    if(x==0) return d[x]=0;
    if(d[x]!=-1) return d[x];
    else d[x]=0;

    if(last.count(p[x]) == 0) return d[x]=f(x-1);
    else {
        printf("last[p[%d]: %d]: %d\n", x, p[x], last[p[x]].back());
        return d[x] = max(f(x-1), f(last[p[x]].back())+1);
    }
}
long long combi(long long n) {
    return n*(n-1LL)/2LL;
}
int main() {
    int t,n,k,in;
    long long ans;
    scanf("%d", &t);
    while(t--) {
        ans=0LL;
        memset(d, -1, sizeof(d));
        memset(p, 0, sizeof(p));
        last.clear();
        scanf("%d%d",&n,&k);
        last[0].push_back(0);
        for(int i=1; i<=n; i++) {
            scanf("%d", &in);
            p[i] = (p[i-1]+in)%k;
            last[p[i]].push_back(i);
        }
        for(pair<const int, vector<int> > &it : last) {
            //printf("%d %lu\n", it.first, it.second.size());
            if(it.second.size() >= 2) ans = (ans+combi(it.second.size()))%MOD;
        }
        printf("%lld %d\n", ans, f(n));

        for(int i=0; i<=n; i++) {
            printf("%d ", d[i]);
        }
        puts("");
    }
    return 0;
}
