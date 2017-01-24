#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod = 5000000;
vector<int> v;
ll d[100001], bit[100001];
void add(int i, int by) {
    for(;i<=100000;i+=i&-i) bit[i]=(bit[i]+by)%mod;
}
int query(int i) {
    int ret=0;
    for(;i>=1;i-=i&-i) ret=(ret+bit[i])%mod;
    return ret;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    for(int i=0; i<n; i++) d[i]=1;
    for(int len=2; len<=k; len++) {
        memset(bit,0,sizeof(bit));
        for(int i=0; i<n; i++) {
            add(v[i], d[i]);
            d[i]=query(v[i]-1);
        }
    }
    int ans=0;
    for(int i=0; i<n; i++) ans=(ans+d[i])%mod;
    printf("%d\n", ans);
    return 0;
}
