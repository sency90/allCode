#include <stdio.h>
int v[1000000];
long long n, m, mx=0, ans=0;
void bs(long long l, long long r) {
    if(l>r) return;
    long long mid = (l+r)/2;
    long long sum=0;
    for(int i=0; i<n; i++) {
        if(v[i]>mid) sum+=v[i]-mid;
    }
    if(sum>=m) {
        if(ans<mid) ans=mid;
        bs(mid+1,r);
    } else bs(l,mid-1);

}
int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d",&v[i]);
        if(mx<v[i]) mx=v[i];
    }
    bs(0,mx-1);
    printf("%lld", ans);
    return 0;
}
