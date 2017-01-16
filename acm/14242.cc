#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;
typedef bitset<17> b17;
typedef long long ll;
bool g[17][17];
const ll M = 1e9+7LL;
void mod(ll &sum) { if(sum>=M) sum%=M; }
ll spow(int one) {
    if(one==0) return 1LL;
    ll ret=spow(one>>1); mod(ret);
    ret*=ret; mod(ret);
    if(one&1) ret<<=1, mod(ret);
    return ret;
}
ll fact(int n) {
    ll ret=1LL;
    for(;n;n--) ret*=n;
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    int lim = 1<<(n-1);
    ll sum = 0LL;
    for(int i=0; i<lim; i++) {
        b17 b(i);
        memset(g,false,sizeof(g));
        for(int j=0; j<n-1; j++) {
            if(b[j]) {
                for(int k=0; k<=j; k++) {
                    for(int l=j+1; l<n; l++) {
                        if(k==j && l==j+1) continue;
                        g[k][l]=true;
                    }
                }
            }
        }
        int one=0, two=0;
        for(int k=0; k<n; k++) {
            for(int l=k+2; l<n; l++) {
                if(!g[k][l]) one++;
                else two++;
            }
        }
        sum+=spow(one); mod(sum);
    }
    ll ndiv2=fact(n)>>1; mod(ndiv2);
    sum*=ndiv2; mod(sum);
    printf("%lld", sum);
    return 0;
}
