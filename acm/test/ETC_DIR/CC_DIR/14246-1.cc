#include <cstdio>
using namespace std;
typedef long long ll;
ll v[100001], psum[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
        psum[i]=psum[i-1]+v[i];
    }
    ll k; scanf("%lld", &k);
    ll sum=0LL, cnt=0LL;
    for(int i=1,b=0; i<=n; i++) {
        if(psum[i]-psum[b]>k) {
            int c=b;
            for(int j=b; j<i; j++) {
                if(psum[i]-psum[j]>k) c=j;
                else break;
            }
            cnt+=c+1;
            b=c;
        }
    }
    printf("%lld", cnt);
    return 0;
}
