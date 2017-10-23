#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[4001],b[4001],c[4001],d[4001],y[16000002];
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            y[cnt++]=c[i]+d[j];
        }
    }
    int ubnd,lbnd;
    ll ans=0;
    sort(y,y+cnt);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x=-(a[i]+b[j]);
            int lo=0, hi=cnt-1;
            while(lo<=hi) {
                int mid = (lo+hi)>>1;
                if(y[mid]<x) lo=mid+1;
                else hi=mid-1;
            }
            if(y[lo]!=x||lo==cnt) continue;
            lbnd = lo;

            lo=0, hi=cnt-1;
            while(lo<=hi) {
                int mid = (lo+hi)>>1;
                if(y[mid]<=x) lo=mid+1;
                else hi=mid-1;
            }
            ubnd = lo;

            ans+=ubnd-lbnd;
        }
    }
    printf("%lld", ans);
    return 0;
}
