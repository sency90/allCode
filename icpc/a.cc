#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool chk[(1<<20)+1];
vector<pair<int,long long> > v[(1<<20)+1];
long long mx=0LL;
void dfs(int x, long long sum) {
    chk[x]=true;
    for(int i=0; i<v[x].size(); i++) {
        int y=v[x][i].first;
        long long w=v[x][i].second;
        if(chk[y]) continue;
        mx = max(mx, sum+w);
        dfs(y,sum+w);
    }
}
int main() {
    int n,t=0;
    long long in;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &in);
        v[i].push_back(make_pair((i<<1)+t,in));
        t^=1;
    }
    chk[0]=true;
    dfs(1,0);
    printf("test %lld\n", mx);
    printf("%lld", mx*(1LL<<n));
    return 0;
}
