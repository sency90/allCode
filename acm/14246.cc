#include <cstdio>
using namespace std;
typedef long long ll;
ll v[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    int k; scanf("%d",&k);
    ll cnt=0LL;
    for(int i=0; i<n; i++) {
        if(v[i]>k) cnt++;
    }
    if(n==1) return 0&printf("%lld", cnt);
    ll b=0, sum=0LL;
    bool flag=true;
    for(int i=0; i<n;) {
        if(flag) sum+=v[i];
        if(sum>k) {
            cnt+=b+1;
            sum-=v[b];
            b++;
            if(i<b) i++;
            flag=false;
        } else {
            i++;
            flag=true;
        }
    }
    printf("%lld", cnt);
    return 0;
}
