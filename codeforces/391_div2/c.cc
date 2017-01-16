#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[1000001];
const int mod = 1e9+7;
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        int g; scanf("%d", &g);
        while(g--) {
            int x; scanf("%d", &x);
            v[x].push_back(i);
        }
    }
    sort(v+1,v+1+m);
    int cnt=1, ans=1;
    for(int i=2; i<=m; i++) {
        if(v[i-1]==v[i]) {
            cnt++;
            ans = (long long)ans*cnt%mod;
        } else cnt=1;
    }
    printf("%d", ans);
    return 0;
}
