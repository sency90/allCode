#include <stdio.h>
int v[100002];
inline int ABS(int x) { return x<0?-x:x; }
const int inf = 0x3f3f3f3f;
int a,b,mn=inf;
int main() {
    int n; scanf("%d",&n);
    v[0]=inf; v[n+1]=inf;
    for(int i=1; i<=n; i++) {
        scanf("%d",&v[i]);
    }
    for(int i=1; i<=n; i++) {
        int x=-v[i],lo=1,hi=n;
        while(lo<=hi) {
            int mid = (lo+hi)>>1;
            if(v[mid]<x) lo=mid+1;
            else hi=mid-1;
        }
        if(i==lo||i==lo-1) {
            if(mn > ABS(v[i]+v[i-1])) {
                mn = ABS(v[i]+v[i-1]);
                a=i; b=i-1;
            }
            if(mn > ABS(v[i]+v[i+1])) {
                mn = ABS(v[i]+v[i+1]);
                a=i; b=i+1;
            }
        } else {
            if(mn > ABS(v[i]+v[lo-1])) {
                mn = ABS(v[i]+v[lo-1]);
                a=i; b=lo-1;
            }
            if(mn > ABS(v[i]+v[lo])) {
                mn = ABS(v[i]+v[lo]);
                a=i; b=lo;
            }
        }
    }
    if(v[a]<v[b]) printf("%d %d",v[a],v[b]);
    else printf("%d %d",v[b],v[a]);
    return 0;
}
