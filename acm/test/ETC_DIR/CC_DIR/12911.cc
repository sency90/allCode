#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
vector<int> v[100001];
int d[11][100001], sum[100001];
int n,k;
int f(int x, int y) {
    if(x==1) return 1;
    int &ret = d[x][y];
    if(ret>0) return ret;

    if(sum[x]>0) ret = sum[x];
    else {
        for(int i=1; i<=k; i++) {
            sum[x]+=f(x-1,i);
            if(sum[x]>=MOD) sum[x]-=MOD;
        } ret = sum[x];
    }

    for(auto &p : v[y]) {
        ret -= f(x-1,p);
        if(ret<0) ret+=MOD;
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1; i<=k; i++) {
        for(int j=2; i*j<=k; j++) {
            v[i*j].push_back(i);
        }
    }

    long long ans = 0LL;
    for(int i=1; i<=k; i++) {
        ans += f(n,i);
    }
    printf("%lld", ans%MOD);
    return 0;
}
