#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[4001],b[4001],c[4001],d[4001],v[16000002];
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            v[cnt++]=c[i]+d[j];
        }
    }
    ll ans=0;
    sort(v,v+cnt);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x=-(a[i]+b[j]);
            int *p = lower_bound(v,v+cnt,x);
            if(*p!=x) continue;
            ans+=upper_bound(v,v+cnt,x)-p;
        }
    }
    printf("%lld", ans);
    return 0;
}
